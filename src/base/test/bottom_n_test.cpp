// Copyright 2018 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "src/base/bottom_n.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

namespace astc_codec {
namespace base {

using ::testing::ElementsAre;

template<typename T, size_t N>
static void pushAll(BottomN<T>& heap, const T (&arr)[N]) {
  for (auto i : arr) {
    heap.Push(i);
  }
}

TEST(BottomN, Sort) {
  {
    BottomN<int> heap(10);
    EXPECT_TRUE(heap.Empty());
    pushAll(heap, {1, 2});

    EXPECT_EQ(heap.Size(), 2);
    EXPECT_FALSE(heap.Empty());
    EXPECT_THAT(heap.Pop(), ElementsAre(1, 2));
  }

  {
    BottomN<int> heap(6);
    pushAll(heap, {1, 4, 3, 2, 2, 1});

    EXPECT_EQ(heap.Size(), 6);
    EXPECT_THAT(heap.Pop(), ElementsAre(1, 1, 2, 2, 3, 4));
  }
}

TEST(BottomN, Bounds) {
  {
    BottomN<int> heap(4);
    pushAll(heap, {1, 2, 3, 4});
    EXPECT_EQ(heap.Size(), 4);

    heap.Push(0);
    EXPECT_EQ(heap.Size(), 4);

    EXPECT_THAT(heap.Pop(), ElementsAre(0, 1, 2, 3));
  }

  {
    BottomN<int> heap(4);
    pushAll(heap, {4, 3, 2, 1});
    EXPECT_EQ(heap.Size(), 4);

    pushAll(heap, {4, 4, 4, 4});
    EXPECT_EQ(heap.Size(), 4);

    EXPECT_THAT(heap.Pop(), ElementsAre(1, 2, 3, 4));
  }

  {
    BottomN<int> heap(4);
    pushAll(heap, {4, 3, 2, 1});
    EXPECT_EQ(heap.Size(), 4);

    pushAll(heap, {5, 5, 5, 5});
    EXPECT_EQ(heap.Size(), 4);

    EXPECT_THAT(heap.Pop(), ElementsAre(1, 2, 3, 4));
  }

  {
    BottomN<int> heap(4);
    pushAll(heap, {4, 3, 2, 1});
    EXPECT_EQ(heap.Size(), 4);

    pushAll(heap, {0, 0, 0, 0});
    EXPECT_EQ(heap.Size(), 4);

    EXPECT_THAT(heap.Pop(), ElementsAre(0, 0, 0, 0));
  }
}

}  // namespace base
}  // namespace astc_codec
