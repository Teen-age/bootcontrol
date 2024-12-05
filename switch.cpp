#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
void warning();
void bios();
void bootEntries(){
    string result;
    FILE* pipe = popen("sudo efibootmgr | grep Boot[0-9] | awk '{print $2, $3}'", "r");
    
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer; // Append output to result string
    }

    pclose(pipe);

    // Print the result
    cout << result;

}
int main() {
    // Displaying Data
    system("sudo -v");
    cout << "\n";
    cout << "Welcome to BootControl! \n";
    cout << "\n";
    cout << "Choose one of the available options to boot into: \n";
    cout << "----------------------------------------------------- \n";
    bootEntries();
    cout << "----------------------------------------------------- \n";
    warning();
    cout << " - This version supports ONLY up to 10 options. \n";
    cout << "If you have more than 10 boot options to choose from, then the program is likely to produce an error! \n";
    cout << "\033[1;32m[USAGE GUIDE]\033[0m" <<"- Each boot entry corresponds to a certain number from 1 to 10. \n";
    bios();
    cout << " - To get into BIOS/UEFI Firmware, type {0}." << endl;
    cout << "Type {Exit} to exit the program. \n";
    string inputLine;
    cin >> inputLine;
    if (inputLine == "Exit"){
        exit(0);
    }else if(inputLine == "exit"){
        exit(0);
    }
    
    char first = inputLine[0];
    int digit = first - '0';
    int corrected = digit - 1;
    if (corrected == 0){
        system("sudo efibootmgr --bootnext 0000");
        system("sudo reboot");
    }else if (corrected ==1){
        system("sudo efibootmgr --bootnext 0001");
        system("sudo reboot");
    }else if (corrected == 2){
        system("sudo efibootmgr --bootnext 0002");
        system("sudo reboot");
    }else if (corrected == 4){
        system("sudo efibootmgr --bootnext 0003");
        system("sudo reboot");
    }else if (corrected == 5){
        system("sudo efibootmgr --bootnext 0004");
        system("sudo reboot");
    }else if(corrected == 6){
        system("sudo efibootmgr --bootnext 0005");
        system("sudo reboot");
    }else if(corrected == 7){
        system("sudo efibootmgr --bootnext 0006");
        system("sudo reboot");
    }else if(corrected == 8){
        system("sudo efibootmgr --bootnext 0007");
        system("sudo reboot");
    }else if(corrected == 9){
        system("sudo efibootmgr --bootnext 0008");
        system("sudo reboot");
    }else if(corrected == 10){
        system("sudo efibootmgr --bootnext 0009");
        system("sudo reboot");
    }else if(corrected == -1){
        system("sudo systemctl reboot --firmware-setup");
        system("sudo reboot");
    }
    return 0;

    
}


void warning(){
    cout << "\033[1;31m[WARNING!]\033[0m";
}

[[maybe_unused]]
void rgb(){   
    for (int i = 0; i < 256; ++i){
        int red = static_cast<int>((sin(i * 0.0245)+1) * 127.5);
        int green = static_cast<int>((sin(i * 0.0245 + 2) + 1) * 127.5);
        int blue = static_cast<int>((sin(i *0.0245 + 4) + 1)* 127.5);

    cout << "\033[38;2" << red << ";" << green << ";" << blue <<"m"<<"Hello World" << i << "033[0m" << endl;
    }
}

void bios(){
    cout << "\033[1;32m[BIOS FIRMWARE]\033[0m";
}


