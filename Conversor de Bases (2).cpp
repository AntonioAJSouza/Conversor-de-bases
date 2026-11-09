#include <iostream>
#include <string>
#include <cmath> //Biblicoteca para usar potencia

using namespace std;

string correcao2(string numero){
	int size = numero.size();
	string digits;
	string resultado;
	for(int i = 0; i < size/4; i++){
		for(int k = i*2; k < 4; k++){
			char bi4 = numero[i];
			digits += bi4;
		}

		if(digits == "0000"){
    		resultado += "0";
		}
		else if(digits == "0001"){
			resultado += "1";
		}
		else if(digits == "0010"){
			resultado += "2";
		}
		else if(digits == "0011"){
			resultado += "3";
		}
    	else if(digits == "0100"){
    	    resultado += "4";
		}
		else if(digits == "0101"){
			resultado += "5";
		}
		else if(digits == "0110"){
			resultado += "6";
		}
		else if(digits == "0111"){
			resultado += "7";
		}
		else if(digits == "1000"){
			resultado += "8";
		}
		else if(digits == "1001"){
			resultado += "9";
		}    
    	else if(digits == "1010"){
    	    resultado += "A";
		}
		else if(digits == "1011"){
			resultado += "B";
		}
		else if(digits == "1100"){
			resultado += "C";
		}
		else if(digits == "1101"){
			resultado += "D";
		}
		else if(digits == "1110"){
			resultado += "E";
		}
		else if(digits == "1111"){
			resultado += "E";
		}
		
	}
	
	return resultado;
}

string correcao16(string numero){
	int size = numero.size();
	string resultado;
		
    for(int i = 0; i < size; ++i){
    	char digit = numero[i];
    	
    	if(digit == '0'){
    	    resultado += "0000";
		}
		else if(digit == '1'){
			resultado += "0001";
		}
		else if(digit == '2'){
			resultado += "0010";
		}
		else if(digit == '3'){
			resultado += "0011";
		}
    	else if(digit == '4'){
    	    resultado += "0100";
		}
		else if(digit == '5'){
			resultado += "0101";
		}
		else if(digit == '6'){
			resultado += "0110";
		}
		else if(digit == '7'){
			resultado += "0111";
		}
		else if(digit == '8'){
			resultado += "1000";
		}
		else if(digit == '9'){
			resultado += "1001";
		}    
    	else if(digit == 'A' || digit == 'a'){
    	    resultado += "1010";
		}
		else if(digit == 'B' || digit == 'b'){
			resultado += "1011";
		}
		else if(digit == 'C' || digit == 'c'){
			resultado += "1100";
		}
		else if(digit == 'D' || digit == 'd'){
			resultado += "1101";
		}
		else if(digit == 'E' || digit == 'e'){
			resultado += "1110";
		}
		else if(digit == 'F' || digit == 'f'){
			resultado += "1111";
		}
	}
	
	return resultado;
}

string converterBase(string numero, int baseOrigem, int baseDestino) { // Fun��o para converter um n�mero de uma base para outra
    string resultado = ""; // String usada para armazenar o resultado final
    unsigned long long decimal = 0; // Usamos o unsigned long long para suportar armazenar numeros maiores
    
    long size = numero.size(); // Fun��o para pegar o tamanho em digitos do da string n�mero
    
    if(baseOrigem!=10){	// Processo usado para processar bases acima de 10
        int size = numero.size(); // Fun��o para pegar o tamanho em digitos do da string n�mero

        for (int i = 0; i < size; ++i) { // for loop para traduzir digitos de bases acima de 10 para decimal
            char digit = numero[i]; // Fun��o para converter string em vetor de char
            int digitValue; // Vari�vel para armazenar os elemetos traduzidos

            if (digit >= '0' && digit <= '9') { //converter char para int
              digitValue = digit - '0';
			} 
			else if (digit >= 'a' && digit <= 'f') { // converte digito hexadecimal para inteiro
              digitValue = digit - 'a' + 10;
			} 
			else if (digit >= 'A' && digit <= 'F') {
              digitValue = digit - 'A' + 10;
            }         
			else {
                 
                cout << "Digito Hexadecimal Invalido: " << digit << endl; // Fun��o para converter um n�mero de uma base para outra
            }   
            decimal += digitValue * pow(baseOrigem, size - i - 1); // pot�ncia para converter a string n�mero para decimal
        }  
	}
	else{
    	decimal = stoull(numero); //converte string para inteiro
	}

    while (decimal > 0) { // converte de base 10 para a base destino
        int digito = decimal % baseDestino;
        if (digito < 10){
            resultado = to_string(digito) + resultado;
        }
        else{ // caso o digito seja de uma base > 10
            resultado = char('A' + digito - 10) + resultado;
        }
        decimal /= baseDestino; //fim gustavo
    }
    
    return resultado;
}

int main() {
    int baseOrigem, baseDestino, tamanho;
    string numero = "";
    string resultado;
    string dashes(120, '-');
    string setasR (51, '>');
    string setasL (51, '<');
    
    cout<<setasR<<"CONVERSOR DE BASES"<<setasL<<endl
    <<dashes<<endl;
    cout<<"[1]Digite o numero que deseja converter ------------> ";
    cin>>numero;
    cout<<"[2]Digite a base do numero de entrada --------------> ";
    cin>>baseOrigem;
    cout<<"[3]Digite a base para a qual deseja converter ------> ";
    cin>>baseDestino;
    cout<<endl;
    cout<<dashes<<endl;
    
    if(baseOrigem == 16 && baseDestino == 2 && numero.size() > 13){
    	resultado = correcao16(numero);
	}
	else if(baseOrigem == 2 && baseDestino == 16 && numero.size() > 52){
		resultado = correcao2(numero);
	}
    else{
    	resultado = converterBase(numero, baseOrigem, baseDestino);
	}
	
    tamanho = resultado.size();
    cout<<endl<<"[=]O numero convertido eh --------------------------> "<<resultado<<endl;
    cout << "Com " << tamanho << " digitos.";
    
    return 0;
}