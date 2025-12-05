#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//creamos la estructura para los datos de las personas
struct datos
{
    std::string nombre;     
    std::string apellido;   
    long long int id;
    int edad;
    char genero;
    long long int telefono;
};
//estructura de categoria util en clientes y productos
struct categorias
{
     int id;
     std::string nombre;      
     std::string descripcion; 
};
//datos de los productos ya contienen su categoria
struct dat_producto
{
	std::string nombre;      
    long long int id;
    std::string descripcion;  
    int cantidad;
    categorias categoria;  
};
// prototipos de las funciones.
void crear_clientes(std::vector <datos>& personas);
void crear_producto(std::vector <dat_producto>& producto);
void crear_categoria(std::vector <categorias>& categoria);
void guardar(std::vector <datos>& personas , std::vector <dat_producto>& producto , std::vector <categorias>& categoria);


int main()
{
    //variables basicas
    std::vector <datos> personas;
    std::vector <dat_producto> producto;
    std::vector <categorias> categoria;
    //definir cliente base
    personas.push_back({"consumidor", "final",2222222, 100, 'H',0000000000});
    //variables complementarias 
    //string cat_personas ,cat_producto; //  Estas variables se  guarda para actualizar
    //crear swicth para decidir que hacer 
    int opcion;
    while(true)
    {
        std::cout<<"que quieres hacer \n 1. crear clientes \n";
        std::cout<<" 2. crear productos \n 3. crear categorias \n 4. guardar datos \n 5. Salir \n"; 
        //validamos que la entrada sea un numero , si no limpiamos el error y volvemos a preguntar
        if (!(std::cin >> opcion)) {
            std::cout << "ERROR: Opcion no valida.\n";
            std::cin.clear();
            std::cin.ignore(1000 , '\n');
            continue; 
        }

        switch (opcion)
        {
            case 1:
                crear_clientes(personas);
                break;
            case 2:
            	if(categoria.empty())
				crear_categoria(categoria);
                if(!(categoria.empty()))
				crear_producto(producto);
                break;
            case 3:
                crear_categoria(categoria);
                break;
            case 4:
            	guardar(personas , producto , categoria);
            	break;
            // salir del bucle
            case 5:
            	cargar(personas , producto , categoria)
            case 6:
                std::cout << "Saliendo del programa...\n";
                return 0; // Terminar el programa
            default:
                std::cout << "Opcion no reconocida. Intente de nuevo.\n";
                break;
        }
        
	}
		
    return 0;
}

//registrar personas

void crear_clientes(std::vector<datos> &personas) {
    datos nueva_persona;
    //llenado de los datos
    std::cout << "\n _______INGRESO_DE_LOS_DATOS_PARA_LA_PERSONA"<<personas.size()<<"_";
    std::cout << "\n"; 
    std::cout << "Presiona cualquier tecla para iniciar el registro...";
    std::cin.ignore(1000 , '\n');
    std::cin.get();
    std::cin.ignore(1000 , '\n');
    //entrada nombre
    std::cout << "nombre : ";
    std::getline(std::cin, nueva_persona.nombre);
    //verificamos que nombre no este vacio
    while (nueva_persona.nombre.empty())
    {
        std::cout << "ERROR : NOMBRE NO INGRESADO \n";
        std::cout << "nombre : ";
        std::getline(std::cin, nueva_persona.nombre); 
    }
    std::cout << "apellidos : ";
    //entrada apellido
    std::getline(std::cin, nueva_persona.apellido); 
    while (nueva_persona.apellido.empty()) 
    {
        std::cout << "ERROR : APELLIDO NO INGRESADO \n";
        std::cout << "apellido : ";
        std::getline(std::cin, nueva_persona.apellido); 
    }
    //entrada y validacion de id
    std::cout<<"id : ";
     while (true)
    {
        if (!(std::cin >> nueva_persona.id))
        {
            std::cout << " ERROR : AL INGRESAR EL VALOR DE ID NO PUEDE SER UN CARACTER \n";
            std::cout << "id :";
            std::cin.clear();
            std::cin.ignore(1000 , '\n');
        }
        else
        {
            if (nueva_persona.id > 0)
            {
                break;
            }
            else
            {
                std::cout << "ERROR EL ID DEBE SER UN NUMERO ENTERO POSITIVO \n";
                std::cout << "id : ";
            }
        }
    }
    
    //entrada y validacion de edad
    std::cout<<"edad : " ;
    while (true)
    {
        if (!(std::cin >> nueva_persona.edad))
        {
            std::cout << " ERROR : AL INGRESAR EL VALOR DE EDAD NO PUEDE SER UN CARACTER \n";
            std::cout << "edad :";
            std::cin.clear();
            std::cin.ignore(1000 , '\n');
        } 
        else if (nueva_persona.edad <= 0) 
        {
            std::cout << "ERROR : EL VALOR DE EDAD NO PUEDE SER NEGATIVO \n";
            std::cout << "edad :";
        }
        else{
            break;
        }
    }
    
    std::cout << "genero : ('H'/'M')";
    //entrada y validacion de genero
    std::cin >> nueva_persona.genero;
    while (nueva_persona.genero != 'h' and 
           nueva_persona.genero != 'H' and 
           nueva_persona.genero != 'm' and 
           nueva_persona.genero != 'M') 
    {
        std::cout << "ERROR : NO SE RECONOCE EL GENERO (SOLO HAY DOS HOMBRE(H) O MUJER(M)) \n";
        std::cout << "genero : ('H'/'M')";
        //nos deshacemos del error
        std::cin.clear(); 
        std::cin.ignore(1000 , '\n');
        std::cin >> nueva_persona.genero;
    }
    if (nueva_persona.genero == 'h')
        nueva_persona.genero = 'H'; 
    if (nueva_persona.genero == 'm')
        nueva_persona.genero = 'M'; 
		   
		   //entrada y validacion de telefono
    std::cout << "numero telefonico : ";
    while (true)
    {
        if (!(std::cin >> nueva_persona.telefono)) 
        {
            std::cout << " ERROR : AL INGRESAR EL VALOR DE TELEFONO NO PUEDE SER UN CARACTER \n";
            std::cout << "telefono :";
            std::cin.clear();
            std::cin.ignore(1000 , '\n');
        }
        else
        {
            // utilizamos #ll para declararlo como una variable long long
            if (((1000000000LL) <= nueva_persona.telefono) and (nueva_persona.telefono <= (9999999999LL)))
            {
                break;
            }
            else
            {
                std::cout << "ERROR EL TELEFONO DEBE SER UN NUMERO ENTERO POSITIVO DE DIEZ CIFRAS \n";
                std::cout << "telefono :";
            }
        }
    }
    personas.push_back(nueva_persona);
    //limpiamos el bufer  y la pantalla
    std::cin.ignore(1000 , '\n');
    std::cout << "presiona cualquier tecla para continuar";
    std::cin.get();
    std::cin.ignore(1000 , '\n');
    system("clear || cls");
}

//registrar productos

void crear_producto(std::vector <dat_producto>& producto) 
{
    std::cout << "\n--- FUNCION CREAR PRODUCTO (POR HACER) --- \n";
    std::cout << "Presiona Enter para continuar...";
    // CAMBIO: Añadido un 'ignore' y 'get' para pausar
    std::cin.get();
}

//registrar categorias

void crear_categoria(std::vector <categorias>& categoria) 
{
    std::cout << "\n--- FUNCION CREAR CATEGORIA (POR HACER) --- \n";
    std::cout << "Presiona Enter para continuar...";
    // CAMBIO: Añadido un 'ignore' y 'get' para pausar
    std::cin.get();
}

//guardar la imformacion registrada
void guardar(std::vector <datos>& personas , std::vector <dat_producto>& producto , std::vector <categorias>& categoria){
	//guardado de las variables de clientes
	//abrir el archivo de clientes
	
	std::ofstream archivo_clientes("clientesCVS.txt");
	//verificar que se abrio
	if (!archivo_clientes.is_open()) {
        std::cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO clientesCVS.txt ";
        std::cin.ignore();
        std::cin.get();
        main();
    }
    //forma moderna de aceder a vectores
    for (const auto& cliente : personas){
    	//almacenar los datos de cada cliente en una linea
		archivo_clientes<<cliente.nombre<<","<<cliente.apellido<<","<<cliente.id<<",";
		archivo_clientes<<cliente.edad<<","<<cliente.genero<<","<<cliente.telefono;
		archivo_clientes<<"\n";
	}
	archivo_clientes.close();
	
	//gurdar las variables de categorias
	
	std::ofstream archivo_categoria("categoriaCVS.txt");
	if (!archivo_categoria.is_open()) {
        std::cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO categoriasCVS.txt ";
        main();
    }
    for (const auto& cat : categoria){
		archivo_categoria<<cat.id<<","<<cat.nombre<<","<<cat.descripcion<<",";
		archivo_categoria<<"\n";
	}
	archivo_categoria.close();
	
	//guardas las variables de productos
	std::ofstream archivo_productos("productosCVS.txt");
	if (!archivo_productos.is_open()) {
        std::cout << "ERROR NO SE PUDO ABRIR EL ARCHIVO productosCVS.txt ";
        main();
    }
    for (const auto& item : producto){
		archivo_productos<<item.nombre<<","<<item.id<<","<<item.descripcion<<",";
		archivo_productos<<item.cantidad<<","<<item.categoria.id;
		archivo_productos<<"\n";
	}
	archivo_productos.close();
	
}
//cargar imformacion guardada
void cargar(std::vector <datos>& personas , std::vector <dat_producto>& producto , std::vector <categorias>& categoria){

    // limpiar vectores para llenarlos desde cero
    personas.clear();
    producto.clear();
    categoria.clear();
    //variables comlementarias
    std::string linea;
    std::string campo;
    
    std::cout << "CARGANDO DATOS \n";
    //CATEGORIAS
    std::ifstream archivo_categoria("categoriaCVS.txt");
    if (!archivo_categoria.is_open()) std::cout << "ERROR NO SE PUDO ABRIR categoriaCVS.txt\n";
    else {
        // leer linea por linea
        while (std::getline(archivo_categoria, linea)) {
        	//flujo de la cadena  y struct
            std::stringstream aux(linea);
            categorias cat_aux;
            // extraemos el id
            std::getline(aux, campo, ',');
            //string to int == stoi
            cat_aux.id = std::stoi(campo); 
            //extraemos el hombre
            std::getline(aux, campo, ',');
            cat_aux.nombre = campo;
            //extraemos descripcion
            std::getline(aux, campo);
            cat_aux.descripcion = campo;
            //almacenarla en el vector
            categoria.push_back(cat_aux); 
        }
        archivo_categoria.close();
        std::cout << "CATEGORIAS CARGADAS ";
    }


    //CLIENTES
    std::ifstream archivo_clientes("clientesCVS.txt");
    if (!archivo_clientes.is_open()) std::cout << "Error: No se pudo abrir el archivo clientesCVS.txt \n";
    else {
    	//leer uno por uno
    	while (std::getline(archivo_clientes, linea)) {
    		//flujo de la cadena y struc
            std::stringstream aux(linea);
            datos pers_aux;
            //nombre y apellido salen derecho
            std::getline(ss, pers_aux.nombre, ',');
            std::getline(ss, pers_aux.apellido, ',');
            //id
            std::getline(ss, campo, ',');
            //string to long long =stoll
            pers_aux.id = std::stoll(campo);
            //edad
            std::getline(ss, campo, ',');
            pers_aux.edad = std::stoi(campo);
            //genero solo es un carcter sale  derecho
            std::getline(ss, campo, ',');
            pers_aux.genero = campo[0];
            //telefono ya no quedan comas
            std::getline(ss, campo);
            pers_aux.telefono = std::stoll(campo);
            //almacenar en el vector
            personas.push_back(pers_aux);
        }
        archivo_clientes.close();
        std::cout << "CLIENTES CARGADOS";
    }
    
    
    
//_______________________________________________________________________//
    // --- PARTE C: Cargar Productos (Las categorías YA existen) ---
    std::ifstream archivo_productos("productosCVS.txt");
    if (!archivo_productos.is_open()) {
        std::cout << "Error: No se pudo abrir el archivo productosCVS.txt \n";
    } else {
        while (std::getline(archivo_productos, linea)) {
            if (linea.empty()) continue;
            
            std::stringstream ss(linea);
            dat_producto prodTemporal;
            int idCategoriaLeido; // ID temporal de la categoría

            std::getline(ss, prodTemporal.nombre, ',');
            
            std::getline(ss, campo, ',');
            prodTemporal.id = std::stoll(campo);
            
            std::getline(ss, prodTemporal.descripcion, ',');
            
            std::getline(ss, campo, ',');
            prodTemporal.cantidad = std::stoi(campo);

            std::getline(ss, campo); // Leemos el ID de la categoría
            idCategoriaLeido = std::stoi(campo);

            // ¡LÓGICA CLAVE! Buscamos la categoría completa en el vector 'categoria'
            bool encontrada = false;
            for (const auto& cat : categoria) {
                if (cat.id == idCategoriaLeido) {
                    prodTemporal.categoria = cat; // Asignamos el struct completo
                    encontrada = true;
                    break;
                }
            }
            if(!encontrada) {
                std::cout << "Advertencia: No se encontro categoria con ID " << idCategoriaLeido << "\n";
            }

            producto.push_back(prodTemporal); // Añadimos el producto al vector
        }
        archivo_productos.close();
        std::cout << "Productos cargados: " << producto.size() << std::endl;
    }
    
    std::cout << "\n¡Carga de datos completada!\n";
    std::cout << "Presiona Enter para continuar...";
    std::cin.ignore(1000, '\n'); // Limpiamos si había algo
    std::cin.get();
    system("clear || cls");
}

