#ifndef CLASEVENTA_H_INCLUDED
#define CLASEVENTA_H_INCLUDED
/*
-Pel�culas.dat (bkp)
Id Pel�cula (N�mero �nico para cada pel�cula)
(char) Nombre de la pel�cula, G�nero
ID Director (tiene que existir en el archivo de directores)
Duraci�n (minutos)
Calificaci�n
Formato (2D,3D,4D)
Idioma (Castellano o Subtitulado) (Puede ser C o S para la carga)
Sala (ID de sala que tiene que existir en el archivo de salas)
Fecha de inicio de la proyecci�n
Fecha de fin de la proyecci�n
Precio entrada

-Directores.dat (bkp)
Id director (autonum�rico y no se repite)
(char) Nombre, Nacionalidad
Fecha de nacimiento
-Salas.dat (bkp)
Id sala (autonum�rico, no se repite)
Cantidad de butacas
-Ventas.dat (bkp)
n� venta (autonum�rico)
Fecha
Id Pel�cula (que exista en el archivo Pel�cula)
Cantidad de entradas
Importe (que provenga del archivo de Pel�cula + un peque�o costo extra por servicio)
Forma de pago (Efectivo, tarjeta de cr�dito, d�bito)
Algunos datos que mostrar� el programa (para la �administraci�n del cine�):
-Mostrar la recaudaci�n de cada pel�cula
-Mostrar la pel�cula m�s taquillera (m�s cantidad de recaudacion �$�)
-Mostrar recaudacion por cada director
-Mostrar director con m�s recaudaci�n
-Recaudaci�n total del cine


Clases a desarrollar:

*/

class Venta{
private:

int numeroventa; ///SE REFIERE AL NUMERO DEL TICKER DE LA ENTRADA(?
int cantidadEntradas;
char formaPago[3]; ///([E] Efectivo, [C] tarjeta de cr�dito, [D] d�bito)
///LA FORMA DE PAGO NO ENTIENDO XQ ES UN VECTOR DE 3, osea nosotros guardamos un valor char cualquiera
/// y despues preguntamos que valor tiene no ?
Fecha fechaventa;
public:
        void setNumeroventa(int n){numeroventa=n;}
        void setCantidadEntrada(int c){cantidadEntradas=c;}
        void setFormaPago(const char *f){formaPago=f;}
        void setFechaVentaDIA(int d){fechaventa.setDia(d);}
        void setFechaVentaMES(int m){fechaventa.setMes(m);}
        void setFechaVentaANIO(int a){fechaventa.setAnio(a);}

        int getNumeroventa(){return numeroventa;}
        int getCantidadEntrada(){return cantidadEntradas;}
        char getFormadepago(){return formaPago;}
        int getFechaVentaDIA(){return fechaventa.getDia();}
        int getFechaVentaMES(){return fechaventa.getMes();}
        int getFechaVentaANIO(){return fechaventa.getAnio();}

        void Cargar(){
        cout<<"INGRESE EL NUMERO DE VENTA: "<<endl;
        cin>>numeroventa;
        cout<<"NUMERO DE LA CANTIDAD DE ENTRADAS: "<<endl;
        cin>>cantidadEntradas;
        cout<<"INGRESE LA FORMA DE PAGO"<<endl;
        cin>>formaPago;
        cout<<"POR FAVOR INGRESE LA FECHA DE LA VENTA: "<<endl;
        int a,b,c;
        cout<<"INGRESE EL DIA:"<<endl;
        cin>>a;
        setFechaVentaDIA(a);
        cout<<"INGRESE EL MES: "<<endl;
        cin>>b;
        setFechaVentaMES(b);
        cout<<"INGRESE EL ANIO:" <<endl;
        cin>>c;
        setFechaVentaANIO(c);
        cout<<endl;}


        void Mostrar()
        {cout<<"EL NUMERO DE VENTA ES: "<<endl;
        cout<<numeroventa;
        cout<<"EL NUMERO DE LA CANTIDAD DE ENTRADAS ES: "<<endl;
        cout<<cantidadEntradas;
        cout<<"LA FORMA DE PAGO ES:"<<endl;
        cout<<formaPago;
        cout<<"LA FECHA DE LA VENTA ES (dd/mm/aaaa): "<<endl;
        cout<<fechaventa.getDia()<<"/"<<fechaventa.getMes()<<"/"<<fechaventa.getAnio()<<endl;
        cout<<endl;}

bool leerDeDisco(int pos){
    FILE *p;
    p=fopen("ventas.dat", "rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Venta), 0);
    bool leyo=fread(this, sizeof (Venta), 1, p);
    fclose(p);
    return leyo;}

bool grabarEnDisco(){
    FILE *p;
    p=fopen("ventas.dat", "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof (Venta), 1, p);
    fclose(p);
    return escribio;}

};



#endif // CLASEVENTA_H_INCLUDED
