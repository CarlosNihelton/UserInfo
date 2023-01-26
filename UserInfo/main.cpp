#include "pch.h"

int main() {
	using namespace winrt;
	using namespace Windows::Foundation;
	using namespace Windows::System;

	Collections::IVectorView<Windows::System::User> users =
		User::FindAllAsync(UserType::LocalUser, UserAuthenticationStatus::LocallyAuthenticated).get();
	User currentUser = users.GetAt(0);
	IInspectable nameObj = currentUser.GetPropertyAsync(Windows::System::KnownUserProperties::FirstName()).get();
	hstring myname = unbox_value<hstring>(nameObj);
	IInspectable namePrincObj = currentUser.GetPropertyAsync(KnownUserProperties::PrincipalName()).get();
	hstring mynamePrinc = unbox_value<hstring>(namePrincObj);
	IInspectable domainNameObj = currentUser.GetPropertyAsync(KnownUserProperties::DomainName()).get();
	hstring mydomainName = unbox_value<hstring>(domainNameObj);
	IInspectable account = currentUser.GetPropertyAsync(KnownUserProperties::AccountName()).get();
	hstring accountName = unbox_value<hstring>(account);
	IInspectable provider = currentUser.GetPropertyAsync(KnownUserProperties::ProviderName()).get();
	IInspectable provider = currentUser.GetPropertyAsync(KnownUserProperties::ProviderName()).get();
	hstring providerName = unbox_value<hstring>(provider);

	std::wcout << std::format(
		L"User name: {}\nAccount name: {}\nName Principal: {}\nDomain Name: {}\nProvider name: {}\n", myname.c_str(),
		accountName.c_str(), mynamePrinc.c_str(), mydomainName.c_str(), providerName.c_str());
}
