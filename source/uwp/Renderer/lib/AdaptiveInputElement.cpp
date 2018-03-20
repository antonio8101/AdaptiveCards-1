#include "pch.h"
#include "AdaptiveInputElement.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveCards::Rendering::Uwp;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::UI::Xaml;
using namespace ABI::Windows::UI::Xaml::Controls;

namespace AdaptiveCards { namespace Rendering { namespace Uwp
{
    HRESULT AdaptiveInputElementBase::InitializeBaseElement(const std::shared_ptr<AdaptiveCards::BaseInputElement>& sharedModel)
    {
        AdaptiveCardElementBase::InitializeBaseElement(std::static_pointer_cast<AdaptiveCards::BaseCardElement>(sharedModel));
        m_isRequired = sharedModel->GetIsRequired();
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveInputElementBase::get_IsRequired(boolean* isRequired)
    {
        *isRequired = m_isRequired;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveInputElementBase::put_IsRequired(boolean isRequired)
    {
        m_isRequired = isRequired;
        return S_OK;
    }

    HRESULT AdaptiveInputElementBase::SetSharedElementProperties(
        std::shared_ptr<AdaptiveCards::BaseInputElement> sharedCardElement)
    {
        AdaptiveCardElementBase::SetSharedElementProperties(sharedCardElement);
        sharedCardElement->SetIsRequired(m_isRequired);
        return S_OK;
    }
}}}
