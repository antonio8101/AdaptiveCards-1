#include "pch.h"
#include "AdaptiveOpenUrlAction.h"
#include "Util.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveCards::Rendering::Uwp;
using namespace ABI::Windows::Foundation;

namespace AdaptiveCards { namespace Rendering { namespace Uwp
{
    HRESULT AdaptiveOpenUrlAction::RuntimeClassInitialize() noexcept try
    {
        std::shared_ptr<AdaptiveCards::OpenUrlAction> openUrlAction = std::make_shared<AdaptiveCards::OpenUrlAction>();
        return RuntimeClassInitialize(openUrlAction);
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveOpenUrlAction::RuntimeClassInitialize(const std::shared_ptr<AdaptiveCards::OpenUrlAction>& sharedOpenUrlAction) try
    {
        if (sharedOpenUrlAction == nullptr)
        {
            return E_INVALIDARG;
        }

        ComPtr<IUriRuntimeClassFactory> uriActivationFactory;
        RETURN_IF_FAILED(GetActivationFactory(
            HStringReference(RuntimeClass_Windows_Foundation_Uri).Get(),
            &uriActivationFactory));
        std::wstring imageUri = StringToWstring(sharedOpenUrlAction->GetUrl());
        RETURN_IF_FAILED(uriActivationFactory->CreateUri(HStringReference(imageUri.c_str()).Get(), m_url.GetAddressOf()));

        InitializeBaseElement(std::static_pointer_cast<AdaptiveCards::BaseActionElement>(sharedOpenUrlAction));
        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveOpenUrlAction::get_Url(IUriRuntimeClass** url)
    {
        return m_url.CopyTo(url);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveOpenUrlAction::put_Url(IUriRuntimeClass* url) try
    {
        m_url = url;
        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveOpenUrlAction::get_ActionType(ABI::AdaptiveCards::Rendering::Uwp::ActionType* actionType)
    {
        *actionType = ABI::AdaptiveCards::Rendering::Uwp::ActionType::OpenUrl;
        return S_OK;
    }

    HRESULT AdaptiveOpenUrlAction::GetSharedModel(std::shared_ptr<AdaptiveCards::BaseActionElement>& sharedModel) try
    {
        std::shared_ptr<AdaptiveCards::OpenUrlAction> openUrlAction = std::make_shared<AdaptiveCards::OpenUrlAction>();
        RETURN_IF_FAILED(SetSharedElementProperties(std::static_pointer_cast<AdaptiveCards::BaseActionElement>(openUrlAction)));

        if (m_url != nullptr)
        {
            HString urlTemp;
            m_url->get_AbsoluteUri(urlTemp.GetAddressOf());

            std::string urlString;
            RETURN_IF_FAILED(HStringToUTF8(urlTemp.Get(), urlString));
            openUrlAction->SetUrl(urlString);
        }

        sharedModel = openUrlAction;
        return S_OK;
    } CATCH_RETURN;
}}}
