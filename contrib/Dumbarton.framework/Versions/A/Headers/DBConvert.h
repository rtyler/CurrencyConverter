//
//  DBConvert.h
//  Dumbarton
//
//  Created by Allan Hsu on 7/28/06.
//  Copyright 2006 imeem. All rights reserved.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//

#import <Foundation/Foundation.h>

#import "DBMonoIncludes.h"
#import "DBMonoObjectRepresentation.h"

@interface DBConvert : NSObject {

}

+ (int8_t)convertMonoObjectToInt8:(MonoObject *)monoObject;
+ (int16_t)convertMonoObjectToInt16:(MonoObject *)monoObject;
+ (int32_t)convertMonoObjectToInt32:(MonoObject *)monoObject;
+ (int64_t)convertMonoObjectToInt64:(MonoObject *)monoObject;

+ (uint8_t)convertMonoObjectToUInt8:(MonoObject *)monoObject;
+ (uint16_t)convertMonoObjectToUInt16:(MonoObject *)monoObject;
+ (uint32_t)convertMonoObjectToUInt32:(MonoObject *)monoObject;
+ (uint64_t)convertMonoObjectToUInt64:(MonoObject *)monoObject;

+ (int8_t)convertToInt8:(DBMonoObjectRepresentation *)objRep;
+ (int16_t)convertToInt16:(DBMonoObjectRepresentation *)objRep;
+ (int32_t)convertToInt32:(DBMonoObjectRepresentation *)objRep;
+ (int64_t)convertToInt64:(DBMonoObjectRepresentation *)objRep;

+ (uint8_t)convertToUInt8:(DBMonoObjectRepresentation *)objRep;
+ (uint16_t)convertToUInt16:(DBMonoObjectRepresentation *)objRep;
+ (uint32_t)convertToUInt32:(DBMonoObjectRepresentation *)objRep;
+ (uint64_t)convertToUInt64:(DBMonoObjectRepresentation *)objRep;

@end
