/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow_io/core/avro/utils/parse_avro_attrs.h"
#include "tensorflow/core/framework/types.h"
#include "tensorflow/core/lib/core/errors.h"
#include "tensorflow/core/platform/types.h"

namespace tensorflow {
namespace data {

// As boiler plate I used tensorflow/core/util/example_proto_helper.cc and
// therein "ParseSingleExampleAttrs" and
Status CheckValidType(const DataType& dtype) {
  switch (dtype) {
    case DT_BOOL:
    case DT_INT32:
    case DT_INT64:
    case DT_FLOAT:
    case DT_DOUBLE:
    case DT_STRING:
      return Status::OK();
    default:
      return errors::InvalidArgument("Received input dtype: ",
                                     DataTypeString(dtype));
  }
}

}  // namespace data
}  // namespace tensorflow