package io.adaptivecards.renderer.input;

import android.app.DatePickerDialog;
import android.app.Dialog;
import android.os.Bundle;
import android.support.v4.app.DialogFragment;
import android.widget.DatePicker;
import android.widget.EditText;

import io.adaptivecards.objectmodel.DateInput;

import java.text.DateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;

public class DatePickerFragment extends DialogFragment
        implements DatePickerDialog.OnDateSetListener
{
    public void initialize(DateInput dateInput, EditText editText)
    {
        m_dateInput = dateInput;
        m_editText = editText;
    }

    @Override
    public Dialog onCreateDialog(Bundle savedInstanceState)
    {
        Calendar calendar;

        try
        {
            Date value = DateFormat.getDateInstance().parse(m_editText.getText().toString());
            calendar = new GregorianCalendar();
            calendar.setTime(value);
        }
        catch (Exception excep)
        {
            // Use current date as default date
            calendar = Calendar.getInstance();
        }

        return new DatePickerDialog(getActivity(), this, calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH), calendar.get(Calendar.DAY_OF_MONTH));
    }

    @Override
    public void onDateSet(DatePicker view, int year, int month, int dayOfMonth)
    {
        Calendar calendar = new GregorianCalendar(year, month, dayOfMonth);
        Date date = calendar.getTime();
        String value = DateFormat.getDateInstance().format(date);
        m_editText.setText(value);
    }

    private DateInput m_dateInput;
    private EditText m_editText;
}
