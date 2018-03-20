package io.adaptivecards.renderer.inputhandler;

import android.text.TextUtils;
import android.widget.CheckBox;

import io.adaptivecards.objectmodel.BaseInputElement;
import io.adaptivecards.objectmodel.ChoiceInputVector;
import io.adaptivecards.objectmodel.ChoiceSetInput;

import java.text.ParseException;
import java.util.List;
import java.util.Map;
import java.util.Vector;

public class CheckBoxSetInputHandler extends BaseInputHandler
{
    public CheckBoxSetInputHandler(BaseInputElement baseInputElement, List<CheckBox> checkBoxList)
    {
        super(baseInputElement);
        m_checkBoxList = checkBoxList;
    }

    protected List<CheckBox> getCheckBox()
    {
        return m_checkBoxList;
    }

    public String getInput()
    {
        // no need to validate
        ChoiceSetInput choiceSetInput = (ChoiceSetInput) m_baseInputElement;

        Vector<String> resultList = new Vector<String>();
        ChoiceInputVector choiceInputVector = choiceSetInput.GetChoices();
        for (int index = 0;index < m_checkBoxList.size(); index++)
        {
            if (m_checkBoxList.get(index).isChecked())
            {
                resultList.addElement(choiceInputVector.get(index).GetValue());
            }
        }

        return TextUtils.join(";", resultList);
    }

    private List<CheckBox> m_checkBoxList;
}
