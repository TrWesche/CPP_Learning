int sum_to_zero(int start, int step = 1) 
{
    if (start > 0) 
    {
        if (start < step) {
            return start;
        }
        else 
        {
            return start + sum_to_zero(start - step, step);
        }
    }
    else if (start < 0) 
    {
        if (start * -1 < step) {
            return start;
        }
        else 
        {
            return start + sum_to_zero(start - step, step);
        }
    }
    else 
    {
        return 0;
    }
}

// double sum_to_zero(double start, double step = 1.0);