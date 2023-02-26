#pragma once
#include "library/Core.WebView.h"
#include "com/Adapter.h"
#include "com/Annotations.h"
#include "webview/Interfaces.h"

namespace core::webview
{
	class MessageReceivedEventArgs : public com::adapter<IMessageReceivedEventArgs> 
	{
		using base = com::adapter<interface_type>;
	public:
		const_property_t<gsl::wzstring>                        Source;
		const_property_t<gsl::wzstring>                        WebMessageAsJson;
		method_t<1,&interface_type::TryGetWebMessageAsString>  TryGetWebMessageAsString;

	public:
		explicit
		MessageReceivedEventArgs(interface_type* ptr) 
		  : MessageReceivedEventArgs{com::shared_ptr<interface_type>{ptr}}
		{}

		explicit
		MessageReceivedEventArgs(meta::adopt_t, interface_type* ptr) 
		  : MessageReceivedEventArgs{com::shared_ptr<interface_type>{adopt,ptr}}
		{}

		explicit
		MessageReceivedEventArgs(com::shared_ptr<interface_type> ptr)
		  : base{std::move(ptr)},
		    Source{this->property(&interface_type::get_Source)},
		    WebMessageAsJson{this->property(&interface_type::get_WebMessageAsJson)},
		    TryGetWebMessageAsString{this->method<1>(&interface_type::TryGetWebMessageAsString)}
		{}
	};

	class NavigationStartingEventArgs : public com::adapter<INavigationStartingEventArgs> 
	{
		using base = com::adapter<interface_type>;

	public:
		mutable_property_t<::BOOL>       Cancel;
		const_property_t<::BOOL>         IsRedirected;
		const_property_t<::BOOL>         IsUserInitiated;
		const_property_t<::UINT64>       NavigationId;
		const_property_t<gsl::wzstring>  Uri;

	public:
		explicit
		NavigationStartingEventArgs(interface_type* ptr) 
		  : NavigationStartingEventArgs{com::shared_ptr<interface_type>{ptr}}
		{}

		explicit
		NavigationStartingEventArgs(meta::adopt_t, interface_type* ptr) 
		  : NavigationStartingEventArgs{com::shared_ptr<interface_type>{adopt,ptr}}
		{}

		explicit
		NavigationStartingEventArgs(com::shared_ptr<interface_type> ptr)
		  : base{std::move(ptr)},
		    Cancel{this->property(&interface_type::get_Cancel, &interface_type::put_Cancel)},
		    IsRedirected{this->property(&interface_type::get_IsRedirected)},
		    IsUserInitiated{this->property(&interface_type::get_IsUserInitiated)},
		    NavigationId{this->property(&interface_type::get_NavigationId)},
		    Uri{this->property(&interface_type::get_Uri)}
		{}
	};
}
