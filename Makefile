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

SRC_DIR ?= ./src
OBJ_DIR = ./build

SRCS := $(shell find $(SRC_DIR) -name '*.cpp' -or -name '*.c' -or -name '*.s')
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

INC_DIRS := include
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CC := gcc

CFLAGS := -Wall -c -fPIC -MMD -MP -std=c++11 -DPYTHON_WRAPPER
CInc := -I$(BOOST_INC) -I$(PYTHON_INC) $(INC_FLAGS)

CLinkFlags = -shared -Wl,-soname,$@ -Wl,-rpath,$(BOOST_LIB_LOCATION) -L$(BOOST_LIB_LOCATION) -l$(BOOST_LIB_FILE) -l$(BOOST_NUMPY_FILE)

PYTHON_LIB_NAME=DSPPythonWrapper


PHONY: all
all: $(PYTHON_LIB_NAME).so

DSPLib_py.so: $(PYTHON_LIB_NAME).o

%.so: $(OBJS)
	$(CC) $^ $(CLinkFlags) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CInc) -c -o $@ $<

.PHONY: clean

clean:
	rm -rf ./build $(PYTHON_LIB_NAME).so

-include $(DEPS)