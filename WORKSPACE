# Copyright 2018 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

git_repository(
    name = "gtest",
    remote = "https://github.com/google/googletest.git",
    commit = "ba96d0b1161f540656efdaed035b3c062b60e006",
)

new_http_archive(
    name = "honggfuzz",
    url = "https://github.com/google/honggfuzz/archive/1.6.zip",
    sha256 = "c331ac5beebe526bced3043ed3012109e439315b7d74d72760b0aa6d08cc05d2",
    build_file = "third_party/honggfuzz.BUILD",
    strip_prefix = "honggfuzz-1.6",
)

http_archive(
    name = "benchmark",
    url = "https://github.com/google/benchmark/archive/v1.4.1.zip",
    sha256 = "61ae07eb5d4a0b02753419eb17a82b7d322786bb36ab62bd3df331a4d47c00a7",
    strip_prefix = "benchmark-1.4.1",
)
