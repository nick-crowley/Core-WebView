#pragma once
#include "library/Core.WebView.h"
#include <webview2.h>

namespace core::webview 
{
	using IAddScriptToExecuteOnDocumentCreatedCompletedHandler = ::ICoreWebView2AddScriptToExecuteOnDocumentCreatedCompletedHandler;
	using ICreateControllerCompletedHandler = ::ICoreWebView2CreateCoreWebView2ControllerCompletedHandler;
	using ICreateEnvironmentCompletedHandler = ::ICoreWebView2CreateCoreWebView2EnvironmentCompletedHandler;
	using INavigationStartingHandler = ::ICoreWebView2NavigationStartingEventHandler;
	using IExecuteScriptCompletedHandler = ::ICoreWebView2ExecuteScriptCompletedHandler;
	using IWebMessageReceivedHandler = ::ICoreWebView2WebMessageReceivedEventHandler;

	using IController = ::ICoreWebView2Controller;
	using IEnvironment = ::ICoreWebView2Environment;
	using IView = ::ICoreWebView2;
	using ISettings = ::ICoreWebView2Settings;
	using INavigationStartingEventArgs = ::ICoreWebView2NavigationStartingEventArgs;
	using IMessageReceivedEventArgs = ::ICoreWebView2WebMessageReceivedEventArgs;
}
