#pragma once
#include "library/Core.WebView.h"
#include "com/Implements.h"
#include "com/SharedPtr.h"
#include "nstd/Functional.h"
#include "webview/Interfaces.h"

namespace core::webview 
{
	template <meta::Interface Interface, typename Signature = decltype(&Interface::Invoke)>
	class Delegate;

	template <meta::Interface Interface, typename... Params>
	class Delegate<Interface,::HRESULT(Interface::*)(Params...)> 
	  : public com::implements<Interface>
	{
		using type = Delegate<Interface,::HRESULT(Interface::*)(Params...)>;

	public:
		using signature_t = ::HRESULT(Params...);

	private:
		nstd::function<signature_t> m_callback;

	public:
		Delegate(nstd::function<signature_t> fx) : m_callback{fx}
		{}

	public:
		::HRESULT
		__stdcall Invoke(Params... args) override {
			return this->m_callback(std::forward<Params>(args)...);
		}
	};

	template <meta::Interface Interface>
	com::shared_ptr<Interface>
	delegate(nstd::function<typename Delegate<Interface>::signature_t> fx) {
		return com::make_shared<Delegate<Interface>,Interface>(fx);
	}
}
