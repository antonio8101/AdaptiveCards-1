#include "pch.h"

#include "AdaptiveRenderContext.h"
#include "AdaptiveError.h"
#include "AdaptiveWarning.h"
#include "InputValue.h"
#include "Util.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveCards::Rendering::Uwp;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::UI::Xaml;

namespace AdaptiveCards { namespace Rendering { namespace Uwp
{
    HRESULT AdaptiveRenderContext::RuntimeClassInitialize() noexcept
    {
        return S_OK;
    }

    HRESULT AdaptiveRenderContext::RuntimeClassInitialize(
        IAdaptiveHostConfig* hostConfig,
        IAdaptiveElementRendererRegistration* elementRendererRegistration,
        IAdaptiveCardResourceResolvers* resourceResolvers,
        IResourceDictionary* overrideDictionary,
        RenderedAdaptiveCard* renderResult) noexcept try
    {
        m_hostConfig = hostConfig;
        m_elementRendererRegistration = elementRendererRegistration;
        m_renderResult = renderResult;
        m_resourceResolvers = resourceResolvers;
        m_overrideDictionary = overrideDictionary;

        return MakeAndInitialize<AdaptiveActionInvoker>(&m_actionInvoker, renderResult);
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::get_HostConfig(IAdaptiveHostConfig** value)
    {
        return m_hostConfig.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::get_ElementRenderers(IAdaptiveElementRendererRegistration** value)
    {
        return m_elementRendererRegistration.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::get_ActionInvoker(IAdaptiveActionInvoker** value)
    {
        return m_actionInvoker.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::get_ResourceResolvers(IAdaptiveCardResourceResolvers** value)
    {
        return m_resourceResolvers.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::get_OverrideStyles(_COM_Outptr_ IResourceDictionary** overrideDictionary)
    {
        return m_overrideDictionary.CopyTo(overrideDictionary);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::AddError(ABI::AdaptiveCards::Rendering::Uwp::ErrorStatusCode statusCode, HSTRING message)
    {
        ComPtr<AdaptiveError> error;
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveError>(&error, statusCode, message));
        ComPtr<IVector<ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveError*>> errors;
        RETURN_IF_FAILED(m_renderResult->get_Errors(&errors));
        return (errors->Append(error.Detach()));
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::AddWarning(ABI::AdaptiveCards::Rendering::Uwp::WarningStatusCode statusCode, HSTRING message)
    {
        ComPtr<AdaptiveWarning> warning;
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveWarning>(&warning, statusCode, message));
        ComPtr<IVector<ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveWarning*>> warnings;
        RETURN_IF_FAILED(m_renderResult->get_Warnings(&warnings));
        return (warnings->Append(warning.Detach()));
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::AddInputValue(IAdaptiveInputValue* inputValue)
    {
        return m_renderResult->AddInputValue(inputValue);
    }
}}}
