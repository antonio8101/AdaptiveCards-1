#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"
#include "Enums.h"
#include "ImageSet.h"
#include <windows.foundation.h>
#include "AdaptiveCardElement.h"

namespace AdaptiveCards { namespace Rendering { namespace Uwp
{
    class DECLSPEC_UUID("04ed4200-de21-4587-8bc5-74b000809985") AdaptiveImageSet :
        public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
        ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveImageSet,
        ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveCardElement,
        Microsoft::WRL::CloakedIid<ITypePeek>,
        Microsoft::WRL::CloakedIid<AdaptiveCards::Rendering::Uwp::AdaptiveCardElementBase>>
    {
        InspectableClass(RuntimeClass_AdaptiveCards_Rendering_Uwp_AdaptiveImageSet, BaseTrust)

    public:
        AdaptiveImageSet();

        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(_In_ const std::shared_ptr<AdaptiveCards::ImageSet>& sharedImageSet);

        // IAdaptiveImageSet
        IFACEMETHODIMP get_Images(_COM_Outptr_ ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveImage*>** columns);

        IFACEMETHODIMP get_ImageSize(_Out_ ABI::AdaptiveCards::Rendering::Uwp::ImageSize* imageSize);
        IFACEMETHODIMP put_ImageSize(_In_ ABI::AdaptiveCards::Rendering::Uwp::ImageSize imageSize);

        // IAdaptiveCardElement
        IFACEMETHODIMP get_ElementType(_Out_ ABI::AdaptiveCards::Rendering::Uwp::ElementType* elementType);

        IFACEMETHODIMP get_Spacing(_Out_ ABI::AdaptiveCards::Rendering::Uwp::Spacing* spacing) { return AdaptiveCardElementBase::get_Spacing(spacing); }
        IFACEMETHODIMP put_Spacing(_In_ ABI::AdaptiveCards::Rendering::Uwp::Spacing spacing) { return AdaptiveCardElementBase::put_Spacing(spacing); }

        IFACEMETHODIMP get_Separator(_Out_ boolean* separator) { return AdaptiveCardElementBase::get_Separator(separator); }
        IFACEMETHODIMP put_Separator(_In_ boolean separator) { return AdaptiveCardElementBase::put_Separator(separator); }

        IFACEMETHODIMP get_Id(_Out_ HSTRING* id) { return AdaptiveCardElementBase::get_Id(id); }
        IFACEMETHODIMP put_Id(_In_ HSTRING id) { return AdaptiveCardElementBase::put_Id(id); }

        IFACEMETHODIMP get_ElementTypeString(_Out_ HSTRING* value) { return AdaptiveCardElementBase::get_ElementTypeString(value); }

        IFACEMETHODIMP get_AdditionalProperties(_Out_ ABI::Windows::Data::Json::IJsonObject** result) { return AdaptiveCardElementBase::get_AdditionalProperties(result); }
        IFACEMETHODIMP put_AdditionalProperties(_In_ ABI::Windows::Data::Json::IJsonObject* value) { return AdaptiveCardElementBase::put_AdditionalProperties(value); }

        IFACEMETHODIMP ToJson(_Out_ ABI::Windows::Data::Json::IJsonObject** result) { return AdaptiveCardElementBase::ToJson(result); }

        virtual HRESULT GetSharedModel(std::shared_ptr<AdaptiveCards::BaseCardElement>& sharedModel) override;

        // ITypePeek method
        void *PeekAt(REFIID riid) override
        {
            return PeekHelper(riid, this);
        }

    private:
        Microsoft::WRL::ComPtr<ABI::Windows::Foundation::Collections::IVector<ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveImage*>> m_images;
        ABI::AdaptiveCards::Rendering::Uwp::ImageSize m_imageSize;
    };

    ActivatableClass(AdaptiveImageSet);
}}}
