#pragma once
#include "library/Core.WebView.h"
#include "com/Adapter.h"
#include "com/Annotations.h"
#include "webview/Interfaces.h"

namespace core::webview
{
	class View : public com::adapter<IView> 
	{
		using base = com::adapter<interface_type>;

	public:
		interface_type* const            Unwrapped;

		const_property_t<::UINT32>       BrowserProcessId;
		const_property_t<::BOOL>         CanGoBack;
		const_property_t<::BOOL>         CanGoForward;
		const_property_t<ISettings*>     Settings;
		const_property_t<gsl::wzstring>  Source;

	public:
		method_t<0,&interface_type::AddScriptToExecuteOnDocumentCreated>  AddScriptToExecuteOnDocumentCreated;
		method_t<0,&interface_type::ExecuteScript>                        ExecuteScript;
		method_t<0,&interface_type::GoBack>                               GoBack;
		method_t<0,&interface_type::GoForward>                            GoForward;
		method_t<0,&interface_type::Navigate>                             Navigate;
		method_t<0,&interface_type::NavigateToString>                     NavigateToString;
		method_t<0,&interface_type::PostWebMessageAsString>               PostWebMessageAsString;
		method_t<0,&interface_type::Reload>                               Reload;
		method_t<0,&interface_type::Stop>                                 Stop;

	public:
		explicit
		View(interface_type* ptr) 
		  : View{com::shared_ptr<interface_type>{ptr}}
		{}
		
		explicit
		View(meta::adopt_t, interface_type* ptr) 
		  : View{com::shared_ptr<interface_type>{adopt,ptr}}
		{}

		explicit
		View(com::shared_ptr<interface_type> ptr) 
		  : base{ptr},
			Unwrapped{ptr},
			// ~-+-~-+-~-+- Properties ~-+-~-+-~-+-
		    BrowserProcessId{this->property(&interface_type::get_BrowserProcessId)},
		    CanGoBack{this->property(&interface_type::get_CanGoBack)},
		    CanGoForward{this->property(&interface_type::get_CanGoForward)},
		    Settings{this->property(&interface_type::get_Settings)},
		    Source{this->property(&interface_type::get_Source)},
			// ~-+-~-+-~-+- Methods ~-+-~-+-~-+-
		    AddScriptToExecuteOnDocumentCreated{this->method(&interface_type::AddScriptToExecuteOnDocumentCreated)},
		    ExecuteScript{this->method(&interface_type::ExecuteScript)},
		    GoBack{this->method(&interface_type::GoBack)},
		    GoForward{this->method(&interface_type::GoForward)},
		    Navigate{this->method(&interface_type::Navigate)},
		    NavigateToString{this->method(&interface_type::NavigateToString)},
		    PostWebMessageAsString{this->method(&interface_type::PostWebMessageAsString)},
		    Reload{this->method(&interface_type::Reload)},
		    Stop{this->method(&interface_type::Stop)}
		{}
	};
	
}
