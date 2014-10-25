/**
 * JavaScriptCoreCPP
 * Author: Matthew D. Langston
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _JAVASCRIPTCORECPP_RAII_JSPROPERTYATTRIBUTE_HPP_
#define _JAVASCRIPTCORECPP_RAII_JSPROPERTYATTRIBUTE_HPP_

#include <functional>

namespace JavaScriptCoreCPP { namespace RAII {

/*!
  @enum

  @constant None Specifies that a property has no special attributes.
  
  @constant ReadOnly Specifies that a property is read-only.
  
  @constant DontEnum Specifies that a property should not be
  enumerated by JSPropertyEnumerators and JavaScript for...in loops.
  
  @constant DontDelete Specifies that the delete operation should fail
  on a property.
*/
enum class JSPropertyAttribute : ::JSPropertyAttributes {
	None,
	ReadOnly,
	DontEnum,
	DontDelete
};

}} // namespace JavaScriptCoreCPP { namespace RAII {

// Provide a hash function so that a JSPropertyAttribute can be stored
// in an unordered container.
namespace std {

template<>
struct hash<JavaScriptCoreCPP::RAII::JSPropertyAttribute> {
	using argument_type = JavaScriptCoreCPP::RAII::JSPropertyAttribute;
	using result_type   = std::size_t;
	
	using property_attribute_underlying_type = std::underlying_type<JavaScriptCoreCPP::RAII::JSPropertyAttribute>::type;
	const std::hash<property_attribute_underlying_type> property_attribute_hash = std::hash<property_attribute_underlying_type>();
	
	result_type operator()(const argument_type& property_attribute) const {
		return property_attribute_hash(static_cast<property_attribute_underlying_type>(property_attribute));
	}
};
}  // namespace std {

#endif // _JAVASCRIPTCORECPP_RAII_JSPROPERTYATTRIBUTE_HPP_