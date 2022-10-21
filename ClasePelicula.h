#ifndef CLASEPELICULA_H_INCLUDED
#define CLASEPELICULA_H_INCLUDED
class Fecha{
private:
int dia, mes, anio;

public:
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    void Cargar(){
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
    }


};


class Pelicula{
  private:
	 int idPelicula;
	char nombrePelicula[30],genero[20];
	int idDirector;
	int duracion;
	///char formato[3],idioma[2]; ESTO VA EN SALA
	int sala;
	Fecha fechainicio;
    Fecha fechafin;
float precio;
  public:
	    void setidPelicula(int p){idPelicula=p;}
	    void setnombrePelicula(const char *n){strcpy(nombrePelicula,n);}
	    void setgenero(const char *g){strcpy(genero,g);}
	    void setIDdirector(int d){idDirector=d;}
	    void setDuracion(int d){duracion=d;}
	    ///void setFormato()
	    void setSala(int s){sala=s;}
	    void setFechainicioDIA(int d){ fechainicio.getDia(d);}
	    void setFechainicioMES(int m){ fechainicio.getMes(m);}
	    void setFechainicioANIO(int a){ fechainicio.getAnio(a);}
	    void setFechafinDIA(int d){fechafin.getDia(d);}
	    void setFechafinMES(int m){fechafin.getMes(m);}
	    void setFechafinANIO(int a){fechafin.getAnio(a);}
	    void setPrecio( int p){precio=p;}


	    int getidPelicula(){return idPelicula;}
	    char getnombrePelicula(){return nombrePelicula;}
	    char getGenero(){return genero;}
	    int getIDdirector(){return idDirector;}
	    int getDuracion(){return duracion;}
	    int getSala(){return sala;}
	    int getDIAfechainicio(){return fechainicio.getDia();}
	    int getMESfechainicio(){return fechainicio.getMes();}
	    int getANIOfechainicio(){return fechainicio.getAnio();}
	    int getDIAfechafin(){return fechafin.getDia();}
	    int getMESfechafin(){return fechafin.getMes();}
	    int getANIOfechafin(){return fechafin.getAnio();}

bool leerDeDisco(int pos){
    FILE *p;
    p=fopen("peliculas.dat", "rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Pelicula), 0);
    bool leyo=fread(this, sizeof (Pelicula), 1, p);
    fclose(p);
    return leyo;
}

bool grabarEnDisco(){
    FILE *p;
    p=fopen("peliculas.dat", "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof (Pelicula), 1, p);
    fclose(p);
    return escribio;
}


        void Cargar(){


        };


         void Mostrar();
};

#endif // CLASEPELICULA_H_INCLUDED
