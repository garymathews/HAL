/**
 * JavaScriptCoreCPP
 * Author: Matthew D. Langston
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "JavaScriptCoreCPP/RAII/JSContextGroup.hpp"
#include "JavaScriptCoreCPP/RAII/JSContext.hpp"
#include "JavaScriptCoreCPP/RAII/JSClass.hpp"

namespace JavaScriptCoreCPP { namespace RAII {

JSContext JSContextGroup::CreateContext() const {
	return JSContext(*this);
}

JSContext JSContextGroup::CreateContext(JSClass global_object_class) const {
	return JSContext(*this, global_object_class);
}

}} // namespace JavaScriptCoreCPP { namespace RAII {
