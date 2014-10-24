// -*- mode: c++ -*-
//
//  Author: Matt Langston
//  Copyright (c) 2014 Appcelerator. All rights reserved.
//

#include "JavaScriptCoreCPP/RAII/JSContext.hpp"
#include "JavaScriptCoreCPP/RAII/JSValue.hpp"
#include "JavaScriptCoreCPP/RAII/JSObject.hpp"
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cassert>

namespace JavaScriptCoreCPP { namespace RAII {

JSValue JSContext::JSEvaluateScript(const JSString& script, const JSString& source_url, int starting_line_number) {
	JSValueRef js_value_ref { nullptr };
	const JSObjectRef this_object { nullptr };
	const JSStringRef source_url_ref = (source_url.length() > 0) ? static_cast<JSStringRef>(source_url) : nullptr;
	JSValueRef exception { nullptr };
	js_value_ref = ::JSEvaluateScript(js_global_context_ref_, script, this_object, source_url_ref, starting_line_number, &exception);
	
	if (exception) {
		// assert(!js_object_ref);
		static const std::string log_prefix { "MDL: JSEvaluateScript: " };
		const std::string message = static_cast<std::string>(JSValue(js_global_context_ref_, exception));
		std::clog << log_prefix << " [ERROR] " << message << std::endl;
		throw std::invalid_argument(message);
	}

	JSValue result(js_global_context_ref_, js_value_ref);
	JSValueUnprotect(js_global_context_ref_, js_value_ref);
	return result;
}


JSValue JSContext::JSEvaluateScript(const JSString& script, const JSObject& this_object, const JSString& source_url, int starting_line_number) {
	JSValueRef js_value_ref { nullptr };
	const JSStringRef source_url_ref = (source_url.length() > 0) ? static_cast<JSStringRef>(source_url) : nullptr;
	JSValueRef exception { nullptr };
	js_value_ref = ::JSEvaluateScript(js_global_context_ref_, script, this_object, source_url_ref, starting_line_number, &exception);
	
	if (exception) {
		// assert(!js_object_ref);
		static const std::string log_prefix { "MDL: JSEvaluateScript: " };
		const std::string message = static_cast<std::string>(JSValue(js_global_context_ref_, exception));
		std::clog << log_prefix << " [ERROR] " << message << std::endl;
		throw std::invalid_argument(message);
	}

	JSValue result(js_global_context_ref_, js_value_ref);
	JSValueUnprotect(js_global_context_ref_, js_value_ref);
	return result;
}

bool JSContext::JSCheckScriptSyntax(const JSString& script, const JSString& source_url, int starting_line_number) {
	const JSStringRef source_url_ref = (source_url.length() > 0) ? static_cast<JSStringRef>(source_url) : nullptr;
	JSValueRef exception { nullptr };
	bool result = ::JSCheckScriptSyntax(js_global_context_ref_, script, source_url_ref, starting_line_number, &exception);
	
	if (exception) {
		// assert(!js_object_ref);
		static const std::string log_prefix { "MDL: JSCheckScriptSyntax: " };
		const std::string message = static_cast<std::string>(JSValue(js_global_context_ref_, exception));
		std::clog << log_prefix << " [ERROR] " << message << std::endl;
		throw std::invalid_argument(message);
	}

	return result;
}

}} // namespace JavaScriptCoreCPP { namespace RAII {