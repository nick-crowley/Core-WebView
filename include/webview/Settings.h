#pragma once
#include "library/Core.WebView.h"
#include "com/Adapter.h"
#include "com/Annotations.h"
#include "webview/Interfaces.h"

namespace core::webview 
{
	class Settings : public com::adapter<ISettings> 
	{
		using base = com::adapter<interface_type>;
	public:
		mutable_property_t<::BOOL> AreDefaultContextMenusEnabled;
		mutable_property_t<::BOOL> AreDefaultScriptDialogsEnabled;
		mutable_property_t<::BOOL> AreDevToolsEnabled;
		mutable_property_t<::BOOL> AreHostObjectsAllowed;
		mutable_property_t<::BOOL> IsBuiltInErrorPageEnabled;
		mutable_property_t<::BOOL> IsScriptEnabled;
		mutable_property_t<::BOOL> IsStatusBarEnabled;
		mutable_property_t<::BOOL> IsWebMessageEnabled;		
		mutable_property_t<::BOOL> IsZoomControlEnabled;

	public:
		explicit
		Settings(interface_type* ptr) 
		  : Settings{com::shared_ptr<interface_type>{ptr}}
		{}

		explicit
		Settings(meta::adopt_t, interface_type* ptr) 
		  : Settings{com::shared_ptr<interface_type>{adopt,ptr}}
		{}

		explicit
		Settings(com::shared_ptr<interface_type> ptr)
		  : base{std::move(ptr)},
		    AreDefaultContextMenusEnabled{this->property(&interface_type::get_AreDefaultContextMenusEnabled, &interface_type::put_AreDefaultContextMenusEnabled)},
		    AreDefaultScriptDialogsEnabled{this->property(&interface_type::get_AreDefaultScriptDialogsEnabled, &interface_type::put_AreDefaultScriptDialogsEnabled)},
		    AreDevToolsEnabled{this->property(&interface_type::get_AreDevToolsEnabled, &interface_type::put_AreDevToolsEnabled)},
		    AreHostObjectsAllowed{this->property(&interface_type::get_AreHostObjectsAllowed, &interface_type::put_AreHostObjectsAllowed)},
		    IsBuiltInErrorPageEnabled{this->property(&interface_type::get_IsBuiltInErrorPageEnabled, &interface_type::put_IsBuiltInErrorPageEnabled)},
		    IsScriptEnabled{this->property(&interface_type::get_IsScriptEnabled, &interface_type::put_IsScriptEnabled)},
		    IsStatusBarEnabled{this->property(&interface_type::get_IsStatusBarEnabled, &interface_type::put_IsStatusBarEnabled)},
		    IsWebMessageEnabled{this->property(&interface_type::get_IsWebMessageEnabled, &interface_type::put_IsWebMessageEnabled)},
		    IsZoomControlEnabled{this->property(&interface_type::get_IsZoomControlEnabled, &interface_type::put_IsZoomControlEnabled)}
		{}
	};
}
