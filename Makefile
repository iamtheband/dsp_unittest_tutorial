# Copyright 2018 Sahaj Software Solutions, Inc.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0

# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

PYTHON_VERSION := 3.6m
PYTHON_INC := /import/linux/python/3.6.6/include/python$(PYTHON_VERSION)
BOOST_INC := ./include
BOOST_LIB_LOCATION := ./lib
BOOST_LIB_FILE := boost_python36
BOOST_NUMPY_FILE := boost_numpy36

CC := gcc

CFLAGS := -Wall -c -fPIC -std=c++11
CInc := -I$(BOOST_INC) -I$(PYTHON_INC)

CLinkFlags = -shared -Wl,-soname,$@ -Wl,-rpath,$(BOOST_LIB_LOCATION) -L$(BOOST_LIB_LOCATION) -l$(BOOST_LIB_FILE) -l$(BOOST_NUMPY_FILE)

PHONY: all
all: EnvTest.so

EnvTest.so: EnvTest.o

%.so: %.o
	gcc $^ $(CLinkFlags) -o $@

%.o: %.cpp
	gcc $(CFLAGS) $(CInc) $^
