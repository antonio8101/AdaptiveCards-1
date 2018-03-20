#include "pch.h"
#include "AdaptiveTextBlock.h"
#include "Util.h"
#include "DateTimeParser.h"
#include <windows.foundation.collections.h>

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveCards::Rendering::Uwp;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::UI::Xaml;
using namespace ABI::Windows::UI::Xaml::Controls;

namespace AdaptiveCards { namespace Rendering { namespace Uwp
{
    HRESULT AdaptiveTextBlock::RuntimeClassInitialize() noexcept try
    {
        std::shared_ptr<AdaptiveCards::TextBlock> textBlock = std::make_shared<AdaptiveCards::TextBlock>();
        return RuntimeClassInitialize(textBlock);
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::RuntimeClassInitialize(const std::shared_ptr<AdaptiveCards::TextBlock>& sharedTextBlock) try
    {
        if (sharedTextBlock == nullptr)
        {
            return E_INVALIDARG;
        }

        m_wrap = sharedTextBlock->GetWrap();
        m_subtle = sharedTextBlock->GetIsSubtle();
        m_maxLines = sharedTextBlock->GetMaxLines();

        m_textSize = static_cast<ABI::AdaptiveCards::Rendering::Uwp::TextSize>(sharedTextBlock->GetTextSize());
        m_textWeight = static_cast<ABI::AdaptiveCards::Rendering::Uwp::TextWeight>(sharedTextBlock->GetTextWeight());
        m_foregroundColor = static_cast<ABI::AdaptiveCards::Rendering::Uwp::ForegroundColor>(sharedTextBlock->GetTextColor());
        m_horizontalAlignment = static_cast<ABI::AdaptiveCards::Rendering::Uwp::HAlignment>(sharedTextBlock->GetHorizontalAlignment());

        RETURN_IF_FAILED(UTF8ToHString(sharedTextBlock->GetText(), m_text.GetAddressOf()));
        RETURN_IF_FAILED(UTF8ToHString(sharedTextBlock->GetLanguage(), m_language.GetAddressOf()));

        InitializeBaseElement(std::static_pointer_cast<BaseCardElement>(sharedTextBlock));
        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::get_Text(HSTRING* text)
    {
        return m_text.CopyTo(text);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::put_Text(HSTRING text)
    {
        return m_text.Set(text);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::get_Size(ABI::AdaptiveCards::Rendering::Uwp::TextSize* textSize)
    {
        *textSize = m_textSize;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::put_Size(ABI::AdaptiveCards::Rendering::Uwp::TextSize textSize)
    {
        m_textSize = textSize;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::get_Weight(ABI::AdaptiveCards::Rendering::Uwp::TextWeight* textWeight)
    {
        *textWeight = m_textWeight;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::put_Weight(ABI::AdaptiveCards::Rendering::Uwp::TextWeight textWeight)
    {
        m_textWeight = textWeight;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::get_Color(ABI::AdaptiveCards::Rendering::Uwp::ForegroundColor* foregroundColor)
    {
        *foregroundColor = m_foregroundColor;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::put_Color(ABI::AdaptiveCards::Rendering::Uwp::ForegroundColor foregroundColor)
    {
        m_foregroundColor = foregroundColor;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::get_Wrap(boolean* wrap)
    {
        *wrap = m_wrap;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::put_Wrap(boolean wrap)
    {
        m_wrap = wrap;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::get_IsSubtle(boolean* isSubtle)
    {
        *isSubtle = m_subtle;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::put_IsSubtle(boolean isSubtle)
    {
        m_subtle = isSubtle;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::get_MaxLines(UINT32* maxLines)
    {
        *maxLines = m_maxLines;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::put_MaxLines(UINT32 maxLines)
    {
        m_maxLines = maxLines;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::get_HorizontalAlignment(ABI::AdaptiveCards::Rendering::Uwp::HAlignment* alignment)
    {
        *alignment = m_horizontalAlignment;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::put_HorizontalAlignment(ABI::AdaptiveCards::Rendering::Uwp::HAlignment alignment)
    {
        m_horizontalAlignment = alignment;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::get_Language(HSTRING* language)
    {
        return m_language.CopyTo(language);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::put_Language(HSTRING language)
    {
        return m_language.Set(language);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveTextBlock::get_ElementType(ElementType* elementType)
    {
        *elementType = ElementType::TextBlock;
        return S_OK;
    }

    HRESULT AdaptiveTextBlock::GetSharedModel(std::shared_ptr<AdaptiveCards::BaseCardElement>& sharedTextBlock) try
    {
        std::shared_ptr<AdaptiveCards::TextBlock> textBlock = std::make_shared<AdaptiveCards::TextBlock>();

        RETURN_IF_FAILED(SetSharedElementProperties(std::static_pointer_cast<AdaptiveCards::BaseCardElement>(textBlock)));

        textBlock->SetWrap(m_wrap);
        textBlock->SetIsSubtle(m_subtle);
        textBlock->SetMaxLines(m_maxLines);
        textBlock->SetTextSize(static_cast<AdaptiveCards::TextSize>(m_textSize));
        textBlock->SetTextWeight(static_cast<AdaptiveCards::TextWeight>(m_textWeight));
        textBlock->SetTextColor(static_cast<AdaptiveCards::ForegroundColor>(m_foregroundColor));
        textBlock->SetHorizontalAlignment(static_cast<AdaptiveCards::HorizontalAlignment>(m_horizontalAlignment));

        std::string text;
        RETURN_IF_FAILED(HStringToUTF8(m_text.Get(), text));
        textBlock->SetText(text);

        std::string language;
        RETURN_IF_FAILED(HStringToUTF8(m_language.Get(), language));
        textBlock->SetLanguage(language);

        sharedTextBlock = textBlock;
        return S_OK;
    } CATCH_RETURN;
}}}
