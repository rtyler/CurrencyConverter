//
//  DBInvoke.h
//  Dumbarton
//
//  Copyright (C) 2005, 2006 imeem, inc. All rights reserved.
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

#import "DBMonoIncludes.h"

//Cache Debugging
void DBInvokeLogCache(BOOL freeContents);

//Method Invocation
MonoObject *DBMonoClassInvoke(MonoClass *monoClass, const char *methodName, int numArgs, va_list va_args);
MonoObject *DBMonoObjectInvoke(MonoObject *monoObject, const char *methodName, int numArgs, va_list va_args);

//Property Access
MonoObject *DBMonoObjectGetProperty(MonoObject *monoObject, const char *propertyName);
void DBMonoObjectSetProperty(MonoObject *monoObject, const char *propertyName, MonoObject *valueObject);
MonoObject *DBMonoClassGetProperty(MonoClass *monoClass, const char *propertyName);
void DBMonoClassSetProperty(MonoClass *monoClass, const char *propertyName, MonoObject *valueObject);

//Field Access
void DBMonoObjectGetField(MonoObject *monoObject, const char *fieldName, void *valueObject);
void DBMonoObjectSetField(MonoObject *monoObject, const char *fieldName, MonoObject *valueObject);
void DBMonoClassGetField(MonoClass *monoClass, const char *fieldName, void *valueObject);
void DBMonoClassSetField(MonoClass *monoClass, const char *fieldName, MonoObject *valueObject);

//Indexer Access
MonoObject *DBMonoObjectGetIndexedObject(MonoObject *monoObject, void *indexObject);
void DBMonoObjectSetIndexedObject(MonoObject *monoObject, void *indexObject, MonoObject *valueObject);

//Constructor Access
MonoObject *DBMonoObjectConstruct(MonoClass *monoClass, int numArgs, ...);
MonoObject *DBMonoObjectVarArgsConstruct(MonoClass *monoClass, int numArgs, va_list va_args);
MonoObject *DBMonoObjectSignatureConstruct(MonoClass *monoClass, const char *signature, int numArgs, ...);
MonoObject *DBMonoObjectSignatureVarArgsConstruct(MonoClass *monoClass, const char *signature, int numArgs, va_list va_args);