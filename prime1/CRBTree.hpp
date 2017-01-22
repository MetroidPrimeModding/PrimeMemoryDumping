#ifndef PRIME_WATCH_DUMP_CRBTREE_HPP
#define PRIME_WATCH_DUMP_CRBTREE_HPP

#include <iostream>
#include <vector>
#include "game_value.h"

template<class T>
class CRBTreeNode : public game_value<16 + T::size> {
    static_assert(T::size > 0, "Attempting to create tree node of an object with undefined size");
public:
    CRBTreeNode(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value<16 + T::size>(base_ptr, ptr_offset) {}

    game_ptr<CRBTreeNode<T>> left = game_ptr<CRBTreeNode<T>>(this->ptr(), 0x0);
    game_ptr<CRBTreeNode<T>> right = game_ptr<CRBTreeNode<T>>(this->ptr(), 0x4);
    game_ptr<CRBTreeNode<T>> parent = game_ptr<CRBTreeNode<T>>(this->ptr(), 0x8);
    game_u32 redOrBlack = game_u32(this->ptr(), 0xC);
    T data = T(this->ptr(), 0x10);

    inline std::vector<T> inOrder() {
      std::vector<T> contents;

      auto l = left.deref();
      if (l.ptr() != 0) {
        auto lContents = l.inOrder();
        contents.insert(contents.end(), lContents.begin(), lContents.end());
      }

      contents.push_back(data);

      auto r = right.deref();
      if (r.ptr() != 0) {
        auto rContents = r.inOrder();
        contents.insert(contents.end(), rContents.begin(), rContents.end());
      }

      return contents;
    }

    inline std::vector<nlohmann::json> inOrderJson() {
      std::vector<nlohmann::json> contents;

      auto l = left.deref();
      if (l.ptr() != 0) {
        auto lContents = l.inOrderJson();
        contents.insert(contents.end(), lContents.begin(), lContents.end());
      }

      contents.push_back(data.json());

      auto r = right.deref();
      if (r.ptr() != 0) {
        auto rContents = r.inOrderJson();
        contents.insert(contents.end(), rContents.begin(), rContents.end());
      }

      return contents;
    }

    inline nlohmann::json json() {
      return nlohmann::json(inOrderJson());
    }
};

template<class T>
class CRBTree : public game_value<16> {
    static_assert(T::size > 0, "Attempting to create tree of an object with undefined size");
public:
    CRBTree(uint32_t base_ptr, uint32_t ptr_offset = 0) : game_value<16>(base_ptr, ptr_offset) {}

    game_u32 size = game_u32(ptr(), 0x0);
    game_ptr<CRBTreeNode<T>> first = game_ptr<CRBTreeNode<T>>(ptr(), 0x4);
    game_ptr<CRBTreeNode<T>> last = game_ptr<CRBTreeNode<T>>(ptr(), 0x8);
    game_ptr<CRBTreeNode<T>> root = game_ptr<CRBTreeNode<T>>(ptr(), 0xC);

    inline nlohmann::json json() {
      if (root.deref().ptr() == 0) {
        std::vector<nlohmann::json> empty;
        return nlohmann::json(empty);
      } else {
        return root.deref().json();
      }
    }
};

#endif //PRIME_WATCH_DUMP_CRBTREE_HPP
