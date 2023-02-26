#pragma once
#include "library/Core.WebView.h"
#include "com/Adapter.h"
#include "com/Annotations.h"
#include "webview/Interfaces.h"

namespace core::webview {

	class Controller : public com::adapter<IController> 
	{
		using base = com::adapter<interface_type>;

	public:
		mutable_property_t<::RECT>                                       Bounds;
		mutable_property_t<::BOOL>                                       IsVisible;
		mutable_property_t<::HWND>                                       ParentWindow;
		mutable_property_t<double>                                       ZoomFactor;
		const_property_t<IView*>                                         WebView;
		method_t<0,&interface_type::Close>                               Close;
		method_t<0,&interface_type::NotifyParentWindowPositionChanged>   NotifyParentWindowPositionChanged;
		method_t<0,&interface_type::SetBoundsAndZoomFactor>              SetBoundsAndZoomFactor;

	public:
		explicit
		Controller(interface_type* ptr)
		  : Controller{com::shared_ptr<interface_type>{ptr}}
		{}

		explicit
		Controller(meta::adopt_t, interface_type* ptr)
		  : Controller{com::shared_ptr<interface_type>{adopt,ptr}}
		{}

		explicit
		Controller(com::shared_ptr<interface_type> ptr) 
		  : base{std::move(ptr)},
		    Bounds{this->property(&interface_type::get_Bounds, &interface_type::put_Bounds)},
		    IsVisible{this->property(&interface_type::get_IsVisible, &interface_type::put_IsVisible)},
		    ParentWindow{this->property(&interface_type::get_ParentWindow, &interface_type::put_ParentWindow)},
		    ZoomFactor{this->property(&interface_type::get_ZoomFactor, &interface_type::put_ZoomFactor)},
		    WebView{this->property(&interface_type::get_CoreWebView2)},
			Close{this->method(&interface_type::Close)},
			NotifyParentWindowPositionChanged{this->method(&interface_type::NotifyParentWindowPositionChanged)},
			SetBoundsAndZoomFactor{this->method(&interface_type::SetBoundsAndZoomFactor)}
		{}
	};
}
