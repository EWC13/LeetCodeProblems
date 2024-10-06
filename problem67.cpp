class Solution {
public:
    string addBinary(string a, string b) {
        char carry = '0';

        a = reverse(a);
        b = reverse(b);

        int iterateSize = 0;
        string sum = "";

        cout << a << endl;
        cout << b << endl;
        if (a.length() > b.length())
        {
            iterateSize = a.length();
            for (int i = 0; i <= iterateSize; i++)
            {
                b += '0';
            }
            cout << b << endl;
        }
        else
        {
            iterateSize = b.length();
            for (int i = 0; i <= iterateSize; i++)
            {
                a += '0';
            }
            cout << a << endl;
        }
        

        for (int i = 0; i <= iterateSize; i++)
        {
            if (carry == '1')
            {
                if (a[i] == '0' and b[i] == '0')
                {
                    sum += '1';
                    carry = '0';
                }
                else if ((a[i] == '1' and b[i] == '0') or (a[i] == '0' and b[i] == '1'))
                {
                    sum += '0';
                    carry = '1';
                }
                else
                {
                    sum += '1';
                    carry = '1';
                }
            }
            else
            {
                if (a[i] == '0' and b[i] == '0')
                {
                    sum += '0';
                }
                else if ((a[i] == '1' and b[i] == '0') || (a[i] == '0' and b[i] == '1'))
                {
                    sum += '1';
                }
                else if (a[i] == '1' and b[i] == '1')
                {
                    sum += '0';
                    carry = '1';
                }
            }
        }

        sum = reverse(sum);
        return sum;
    }

    string reverse(string reversed)
    {
        string newString = "";
        int length = reversed.length();
        char temp;
        for (int i = 0; i < length; i++)
        {
            temp = reversed[i];
            reversed[i] = reversed[length-1];
            reversed[length-1] = temp;
            length--;
        }
        return reversed;
    }
};
