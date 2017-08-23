/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <gtest/gtest.h>

#include "environment.h"

TEST(environment, GetCpusFromString) {
  ASSERT_EQ(GetCpusFromString(""), std::vector<int>());
  ASSERT_EQ(GetCpusFromString("0-2"), std::vector<int>({0, 1, 2}));
  ASSERT_EQ(GetCpusFromString("0,2-3"), std::vector<int>({0, 2, 3}));
  ASSERT_EQ(GetCpusFromString("1,0-3,3,4"), std::vector<int>({0, 1, 2, 3, 4}));
}
