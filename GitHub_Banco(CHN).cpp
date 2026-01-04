// Software - Modelo de Banco 
// Autor - dpuluc-dev
// Instrucciones:  el programa debe de realizarse dentro de la consola, si se sale reinicia el proceso... 
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std; 
int main(void){
	 // Parte 1 - Login
	 char Usuario [30]; 
	 int Pin; 
	 bool acceso = false;
	 int intentos = 0; 
	 const int MAXIMO_INTENTOS = 5; 
	 int opcion;
	 int Sub_Opcion;
	 char res; 
	 // Parte 2 - REGISTRO CLIENTES
	 string Clientes[30];
	 string Targeta[30];
	 string Fecha [30];
	 float Monto [30]; 
	 float Debitar [30]; 
	 int total = 0;  
	 float resultado; 
	 // Parte 3 - CONSULTAR/BUSCAR CLIENTES
	 string buscar;
	 bool encontrado = false;
	 // Parte 4 - ELIMAR CLIENTES
	 char confirmar; 
	 cout<<" - - - - - Banco CHN (Credito Hipotecario Nacional) - - - - - "<<endl;
	 cout<<"| Login | Accede con Usuario y Pin | Maximo de intentos (5) |\n"<<endl;
	 
	 // Usuario: Daniel Puluc && Contraseña/Pin = 1234   <---NOTA!
	 
	 do{
	 	cout<<"Ingresa Usuario: "; 
	 	cin.getline(Usuario, 30); 
	 	cout<<"Ingresa Pin: "; 
	 	cin>>Pin;
	 	cin.ignore(1000, '\n'); 
	 	if(strcmp(Usuario, "Daniel Puluc") == 0 && Pin == 1234){
	 		 cout<<"Acceso correcto, bienvenido "<<Usuario<<endl; 
	 		 acceso = true;
	 		 break; 
		 }else{
		 	 cout<<"Acceso denegado, Intentalo una vez mas!"<<endl;
		 	 intentos++; 
		 }
	 }while(intentos<MAXIMO_INTENTOS); 
	 if(!acceso){
	 	 cout<<" Maximo de intentos alcanzados (Reinicia la consola) "<<endl;
	 } 
	 cout<<" - - - SISTEMA DE AUTOMATIZACION DEL BANCO CHN - - - "<<endl;
	 do{
	 	cout<<"\t\t\tOpciones_Principales"<<endl;
	 	cout<<"1. Depositos Monetarios"<<endl;
	 	cout<<"2. Retiros Monetarios"<<endl;
	 	cout<<"3. Sistema ( CRUD )"<<endl;
	 	cout<<"Selecciona una opcion "<<Usuario<<" "; cin>>opcion; 
	 	switch ( opcion ){
	 		case 1: 
	 		    cout<<" - - -  DEPOSITOS MONETARIOS - - - - "<<endl; 
	 			cout<<"Aviso! - Registre al menos un cliente"<<endl;
	 			if(total<30){
	 			        cout<<"Cliente: ";
	 			        cin.ignore(1000, '\n'); 
	 			     	getline(cin, Clientes[total]); 
	 			    	cout<<"Targeta: ";
	 			    	cin>>Targeta[total];
	 			    	cout<<"Monto: Q";
	 			    	cin>>Monto[total]; 
	 			    	cout<<"Fecha: ";
	 			    	cin>>Fecha[total];
	 			    	total++;
	 				    cout<<"SE REGISTRO CORRECTAMENTE EL CLIENTE\n"<<endl; 
				        }else{
				 	    cout<<"AVISO - ARREGLO LLENO! "<<endl; 
				        } 
				        for(int i=0; i<total; i++){
				 	    cout<<" - - - FACTURA BANCO CHN - - - "<<endl; 
				 	    cout<<"           DEPOSITO            "<<endl;
				 	    cout<<"Registrado en la posicion: "<<i<<endl;
				 	    cout<<"Cliente: #"<<i+1<<endl;
				 	    cout<<"Nombre: "<<Clientes[i]<<endl; 
				 	    cout<<"Targeta: "<<Targeta[i]<<endl;
				 	    cout<<"Monto: Q"<<Monto[i]<<endl;
				 	    cout<<"Fecha: "<<Fecha[i]<<endl;
				     	cout<<"Registrado por: "<<Usuario<<endl;
				 	    cout<<"    Que tenga un buen dia!    "<<endl; 
				 	    cout<<" - - - - - - - - - - - - - - - \n"<<endl;
			        	   }  
				           {
				 	        ofstream archivo("Depositos.txt", ios::app);
				        	for(int i=0; i<total; i++){
				 			archivo<<" - - -  FACTURA BANCO CHN - - - "<<endl; 
				 			archivo<<"            DEPOSITO            "<<endl;
				 	        archivo<<"Registrado en pos: "<<i<<endl;
				           	archivo<<"Cliente #"<<i+1<<endl;
				 	        archivo<<"Nombre: "<<Clientes[i]<<endl; 
				 	        archivo<<"Targeta: "<<Targeta[i]<<endl;
				        	archivo<<"Monto: Q"<<Monto[i]<<endl; 
				        	archivo<<"Fecha: "<<Fecha[i]<<endl; 
				        	archivo<<"Registrado por: "<<Usuario<<endl;
				 	        archivo<<" Que tenga un buen dia! "<<endl; 
				        	archivo<<" - - - - - - - - - - - - - - - - \n"<<endl;
				        	 }		 
		                   } 
		                    break; 
		                    case 2: 
                            cout<<" - - - RETIROS MONETARIOS - - - "<<endl;
                            cout<<"Aviso! - Ingrese el No. Tarjeta: ";
                            cin.ignore(1000,'\n');
                            getline(cin,buscar);
                            encontrado = false;
                            for(int i=0;i<total;i++){
                            if(Targeta[i]==buscar){
                            encontrado = true;
                            cout<<"\n# TARJETA ENCONTRADA CON EXITO!\n";
                            cout<<"Nombre de la cuenta: "<<Clientes[i]<<endl;
                            cout<<"Monto disponible: Q"<<Monto[i]<<endl;
                            cout<<"Monto a retirar: Q";
                            cin>>Debitar[i];
                            if(Debitar[i]<=0){
                            cout<<"\nMonto invalido"<<endl;
                             break;
                             }
                            if(Debitar[i]<=Monto[i]){
                            Monto[i]-=Debitar[i];
                            cout<<"\nMonto retirado correctamente!"<<endl;
                            cout<<"Saldo actual: Q"<<Monto[i]<<endl;
                            cout<<" - - - FACTURA BANCO CHN - - - "<<endl; 
                            cout<<"            RETIRO             "<<endl;
                            cout<<"Registrado en la posicion: "<<i<<endl;
                            cout<<"Cliente: #"<<i+1<<endl;
                            cout<<"Nombre: "<<Clientes[i]<<endl; 
                            cout<<"Targeta: "<<Targeta[i]<<endl;
                            cout<<"Monto retirado: Q"<<Debitar[i]<<endl;
                            cout<<"Fecha: "<<Fecha[i]<<endl;
                            cout<<"Registrado por: "<<Usuario<<endl;
                            cout<<"    Que tenga un buen dia!    "<<endl; 
                            cout<<" - - - - - - - - - - - - - - - \n"<<endl;
                            ofstream archivo("Retiros.txt",ios::app);
                            archivo<<" - - - FACTURA BANCO CHN - - - "<<endl;
                            archivo<<"            RETIRO             "<<endl;
                            archivo<<"Registrado en pos: "<<i<<endl;
                            archivo<<"Cliente #"<<i+1<<endl;
                            archivo<<"Nombre: "<<Clientes[i]<<endl;
                            archivo<<"Targeta: "<<Targeta[i]<<endl;
                            archivo<<"Monto retirado: Q"<<Debitar[i]<<endl;
                            archivo<<"Fecha: "<<Fecha[i]<<endl;
                            archivo<<"Registrado por: "<<Usuario<<endl;
                            archivo<<" - - - - - - - - - - - - - - - - "<<endl<<endl;
                            archivo.close();
                             }else{
                             cout<<"\nSaldo insuficiente, intenta otra cantidad!"<<endl;
                             }
                          break;
                            }
                          }
                        if(!encontrado){
                        cout<<"\nTARJETA NO ENCONTRADA"<<endl;
                        }
                        break;
		                    case 3:
		                    cout<<" - - - SISTEMA CRUD ( CLIENTES ) - - - "<<endl; 
		                    do{
		                    	cout<<"\t\t\tOpciones_del_sistema"<<endl;
		                    	cout<<"1. Consultar cliente"<<endl; 
		                    	cout<<"2. Modificar cliente"<<endl; 
		                    	cout<<"3. Eliminar cliente"<<endl; 
		                    	cout<<"Selecciona tu opcion "<<Usuario; cin>>Sub_Opcion;
								switch  (Sub_Opcion){
										  case 1:
		                    	                cout<<"Consultar Cliente con el servidor\n"<<endl; 
		                    	              	encontrado = false; 
		                    	                cout<<"Nombre Completo: "; 
		                    	                cin.ignore(1000, '\n'); 
		                    	            	getline(cin, buscar); 
		                    	  	            for(int i=0; i<total; i++){
		                    	  		        if(Clientes[i] == buscar){
		                    	  		     	cout<<" - - - DATOS DE LA FACTURA - - -  "<<endl; 
		                    	  		     	cout<<"             DEPOSITO             "<<endl; 
		                    	  		    	cout<<"Registrado en pos: "<<i<<endl; 
		                    	  			    cout<<"Cliente: #"<<i+1<<endl;
		                    	  		    	cout<<"Nombre: "<<Clientes[i]<<endl; 
		                    	  		    	cout<<"Targeta: "<<Targeta[i]<<endl; 
		                    	  		    	cout<<"Monto: Q"<<Monto[i]<<endl; 
		                    	  		    	cout<<"Fecha: "<<Fecha[i]<<endl; 
		                    	  		    	cout<<"Registrado por: "<<Usuario<<endl; 
		                    	  		    	cout<<"         Que tenga buen dia!      "<<endl; 
		                    	  		    	cout<<" - - - - - - - - - - - - - - - -  "<<endl; 
		                    	  		    	cout<<"CLIENTE ENCONTRADO EXITOSAMENTE!\n"<<endl;
		                    	  		    	encontrado = true; 
											  }  
											  
											} 
											 if(!encontrado){
											  	cout<<"CLIENTE NO ENCONTRADO\n"<<endl;
									     	}
										     break; 
										     
										     case 2:
											  		cout<<"Modificacion del cliente con el servidor"<<endl; 
											  		cout<<"Ingrese el nombre completo del cliente a modificar: "<<endl;
											  		cin.ignore(1000, '\n'); 
											  		getline(cin, buscar); 
											  		for(int i=0; i<total; i++){
											  			if(Clientes[i]==buscar){
											  				    encontrado = true; 
											  				 	cout<<" - - - DATOS DE LA FACTURA - - -  "<<endl; 
		                    	  		                     	cout<<"             DEPOSITO             "<<endl; 
		                    	  		                    	cout<<"Registrado en pos: "<<i<<endl; 
		                    	  			                    cout<<"Cliente: #"<<i+1<<endl;
		                    	  		    	                cout<<"Nombre: "<<Clientes[i]<<endl; 
		                    	  		                    	cout<<"Targeta: "<<Targeta[i]<<endl; 
		                    	  		                    	cout<<"Monto: Q"<<Monto[i]<<endl; 
		                    	  		    	                cout<<"Fecha: "<<Fecha[i]<<endl; 
		                    	  		                    	cout<<"Registrado por: "<<Usuario<<endl; 
		                    	  		    	                cout<<"         Que tenga buen dia!      "<<endl; 
		                    	  		                    	cout<<" - - - - - - - - - - - - - - - -  "<<endl; 
		                    	  		                     	cout<<"CLIENTE ENCONTRADO EXITOSAMENTE!\n"<<endl;
		                    	  		                        cout<<"Cliente Nuevo: ";
	 			                                            	getline(cin, Clientes[i]); 
	 			                                            	cin.ignore(1000, '\n'); 
	 			    	                                        cout<<"Targeta: ";
	 			                                            	cin>>Targeta[i];
	 			    	                                        cout<<"Monto: Q";
	 			                                            	cin>>Monto[i]; 
	 			                                                cout<<"Fecha: ";
	 			    	                                        cin>>Fecha[i];
																cout<<"CLIENTE MODIFICADO CORRECTAMENTE\n"<<endl; 
				                                                for(int i=0; i<total; i++){
				 	                                            cout<<" - - - FACTURA BANCO CHN - - - "<<endl; 
				 	                                            cout<<"           DEPOSITO            "<<endl;
				 	                                            cout<<"Registrado en la posicion: "<<i<<endl;
				 	                                            cout<<"Cliente: #"<<i+1<<endl;
				 	                                            cout<<"Nombre: "<<Clientes[i]<<endl; 
				 	                                            cout<<"Targeta: "<<Targeta[i]<<endl;
				 	                                            cout<<"Monto: Q"<<Monto[i]<<endl;
				 	                                            cout<<"Fecha: "<<Fecha[i]<<endl;
				     	                                        cout<<"Registrado por: "<<Usuario<<endl;
				 	                                            cout<<"    Que tenga un buen dia!    "<<endl; 
				 	                                            cout<<" - - - - - - - - - - - - - - - \n"<<endl;
			        	                                         }  
				                                            {
				 	                                       ofstream archivo("Modifiacion_deposito.txt", ios::app);
				                                           for(int i=0; i<total; i++){
				 			                               archivo<<" - - -  FACTURA BANCO CHN - - - "<<endl; 
				 		                                   archivo<<"            DEPOSITO            "<<endl;
				 	                                       archivo<<"Registrado en pos: "<<i<<endl;
				                                           archivo<<"Cliente #"<<i+1<<endl;
				 	                                       archivo<<"Nombre: "<<Clientes[i]<<endl; 
				 	                                       archivo<<"Targeta: "<<Targeta[i]<<endl;
				        	                               archivo<<"Monto: Q"<<Monto[i]<<endl; 
				                                           archivo<<"Fecha: "<<Fecha[i]<<endl; 
				                                           archivo<<"Registrado por: "<<Usuario<<endl;
				 	                                       archivo<<" Que tenga un buen dia! "<<endl; 
				        	                               archivo<<" - - - - - - - - - - - - - - - - \n"<<endl;
				        	                                   }		 
		                                                    } 
		                    	  		                    	break;
											              } 
														} 
														 if(!encontrado){
											  	               cout<<"CLIENTE NO ENCONTRADO\n"<<endl;
									                      	}
										              break; 
										              case 3:
                                                    encontrado = false;
                                                    cout<<"Eliminar cliente del servidor\n"<<endl;
                                                    cout<<"Ingrese el nombre completo del cliente a eliminar: ";
                                                    cin.ignore(1000, '\n');
                                                    getline(cin, buscar);
                                                    for(int i = 0; i < total; i++){
                                                    if(Clientes[i] == buscar){
                                                     encontrado = true;
                                                    cout<<"\nCLIENTE ENCONTRADO\n";
                                                    cout<<"Cliente: "<<Clientes[i]<<endl;
                                                    cout<<"Targeta: "<<Targeta[i]<<endl;
                                                    cout<<"Monto: Q"<<Monto[i]<<endl;
                                                    cout<<"Fecha: "<<Fecha[i]<<endl;                      
                                                    cout << "\n¿Seguro que desea eliminar este cliente? (S/N): ";
                                                    cin>>confirmar;
                                                    if(confirmar == 'S' || confirmar == 's'){
                                                    for(int j = i; j < total - 1; j++){
                                                    Clientes[j] = Clientes[j + 1];
                                                    Targeta[j]  = Targeta[j + 1];
                                                    Monto[j]    = Monto[j + 1];
                                                    Fecha[j]    = Fecha[j + 1];
                                                     }
                                                    total--; 
                                                    cout << "\nCLIENTE ELIMINADO CORRECTAMENTE\n" << endl;
                                                    }else{
                                                     cout << "\nELIMINACIÓN CANCELADA\n" << endl;
                                                    }
                                                    break;
                                                    }
                                                  }
                                             if(!encontrado){
                                             cout << "CLIENTE NO ENCONTRADO\n" << endl;
                                              }
                                              break;
										  } 
									 cout<<" (S/s) Agregar (N/n) Salir --> Sistema Crud "<<endl; 
	                                 cin>>res;
	                             
					      }while(res == 'S' || res == 's');        
					  
		             }
		              cout<<" (S/s) Agregar (N/n) Salir --> Sistema General del banco "<<endl; 
		              cin>>res;
		          
	 }while(res == 'S' || res == 's'); 	
	return 0; 
}