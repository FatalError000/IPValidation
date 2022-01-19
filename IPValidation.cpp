#include <iostream>
#include <string>
using namespace std;

string byteValidation(string byteS)
{
    string result = "";
    int byteI;

    for (int i = 0; i < byteS.length() - 1; i++)
    {
        if ((i > 0) && ((byteS[0] == '0') && (byteS[1] == '0')))
        {
            return result = "Invalid. Two or more zeros in a row detected!";
        }

        if ((i > 0) && (byteS[0] == '0'))
        {
            return result = "Invalid. Invalid position of zero!";
        }
    }
    
    byteI = stoi(byteS);

    if (byteI > 255)
    {
        return result = "Invalid. The value of one of the bytes more than 255";
    }

    result = "Valid";

    return result;
}

string ipValidation(string IPAdress)
{
    string result = "", byteS = "";
    int dotsCounter = 0;
    
    for (int i = 0; i < IPAdress.length(); i++)
    {
        if (!((IPAdress[i] == '.') || ((IPAdress[i] >= '0') && (IPAdress[i] <= '9'))))
        {
            return result = "Invalid. Wrong symbols detected!";
        }

        if ((i == IPAdress.length() - 1) && (IPAdress[i] == '.'))
        {
            return result = "Invalid. Dot as last symbol detected!";
        }

        if ((i > 0) && ((IPAdress[i] == '.') && (IPAdress[i - 1] == '.')))
        {
            return result = "Invalid. Two or more dots in a row detected!";
        }       

        if (IPAdress[i] == '.')
        {
            dotsCounter++;
        }

        if ((i > 0) && (IPAdress[i] == '.'))
        {
            result = byteValidation(byteS);
            byteS = "";

            if (result[0] == 'I')
            {
                break;
            }
        }
        else
        {
            byteS += IPAdress[i];
            
            if (i == IPAdress.length() - 2)
            {
                result = byteValidation(byteS);
            }
        }
    }

    if (dotsCounter != 3)
    {
        result = "Invalid. Incorrect amount of bytes.";
    }

    if (result == "") 
    {
        result = "Valid";
    }    

    return result;
}

void ipAdressCorrectTest()
{
    cout << "Correct IP adresses." << endl;
    cout << "Enter your IP adress : 127.0.0.1" << endl;
    cout << "Your IP adress is " << ipValidation("127.0.0.1") << endl;
    cout << "Enter your IP adress : 255.255.255.255" << endl;
    cout << "Your IP adress is " << ipValidation("255.255.255.255") << endl;
    cout << "Enter your IP adress : 1.2.3.4" << endl;
    cout << "Your IP adress is " << ipValidation("1.2.3.4") << endl;
    cout << "Enter your IP adress : 55.77.213.101" << endl;
    cout << "Your IP adress is " << ipValidation("55.77.213.101") << endl;
}

void ipAdressIncorrectTest()
{
    cout << endl << "Incorrect IP adresses." << endl;
    cout << "Enter your IP adress : 255.256.257.258" << endl;
    cout << "Your IP adress is " << ipValidation("255.256.257.258") << endl;
    cout << "Enter your IP adress : 0.55.33.22." << endl;
    cout << "Your IP adress is " << ipValidation("0.55.33.22.") << endl;
    cout << "Enter your IP adress : 10.00.000.0" << endl;
    cout << "Your IP adress is " << ipValidation("10.00.000.0") << endl;
    cout << "Enter your IP adress : 23.055.255.033" << endl;
    cout << "Your IP adress is " << ipValidation("23.055.255.033") << endl;
    cout << "Enter your IP adress : 65.123..9" << endl;
    cout << "Your IP adress is " << ipValidation("65.123..9") << endl;
    cout << "Enter your IP adress : a.b.c.d" << endl;
    cout << "Your IP adress is " << ipValidation("a.b.c.d") << endl;
}

int main()
{
    string IPAdress = "";

    ipAdressCorrectTest();
    ipAdressIncorrectTest();

    cout << "Enter your IP adress : " << endl;
    cin >> IPAdress;
    cout << "Your IP adress is " << ipValidation(IPAdress) << endl;

    return 0;
}

