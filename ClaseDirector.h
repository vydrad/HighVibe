#ifndef CLASEDIRECTOR_H_INCLUDED
#define CLASEDIRECTOR_H_INCLUDED

class Director{
private:
int Iddirector;
char Nombredirector[30], NacionalidadDirector[20];
Fecha fechanac;
public:
        void setIDdirector(int d){Iddirector=d;}
        void setNombreDirector(const char *n){strcpy(Nombredirector,n);}
        void setNacionalidadDiretor(const char *d){strcpy(NacionalidadDirector,d);}
        void setFechaNacDirDIA(int d){fechanac.getDia(d);}
        void setFechaNacDirMES(int m){fechanac.getDia(m);}
        void setFechaNacDirANIO(int a){fechanac.getDia(a);}

        int getIDdirector(){return Iddirector;}
        const char getNombreDirector(){return Nombredirector;}
        const char getNacionalidadDirector(){return NacionalidadDirector;}
        int getNacDirectorDIA(){return fechanac.getDia();}
        int getNacDirectorMES(){return fechanac.getMes();}
        int getNacDirectorANIO(){return fechanac.getAnio();}


        void Cargar(){
        cout<<"INGRESE EL ID DEL DIRECTOR:"<<endl;
        cin>>Iddirector;
        cout<<"INGRESE EL NOMBRE DEL DIRECTOR: "<<endl;
        cin>>CargarCadena(Nombredirector);
        cout<<"INGRESE LA NACIONALIDAD DEL DIRECTOR: "<<endl;
        cin>>CargarCadena(NacionalidadDirector);
        cout<<"INGRESE LA FECHA DE NACIMIENTO DEL DIRECTOR: "<<endl;
        cout<<"INGRESE EL DIA: "<<endl;
        int a,b,c;
        cin>> a;
        fechanac.setDia(a);
        cout<<"INGRESE EL MES: "<<endl;
        cin>>b;
        cout<<"INGRESE EL ANIO: "<<endl;
        cin>>c;
        cout<<endl;}

        void Mostrar(){
        cout<<"EL ID DEL DIRECTOR ES: "<<Iddirector<<endl;
        cout<<"EL NOMBRE DEL DIRECTOR ES: "<<Nombredirector<<endl;
        cout<<"LA NACIONALIDAD DEL DIRECTOR ES: "<<NacionalidadDirector<<endl;
        cout<<"LA FECHA DE NACIMIENTO ES: "<<endl;
        cout<<fechanac.getDia()<<"/"<<fechanac.getMes()<<"/"<<fechanac.getAnio()<<endl;
        };
};

#endif // CLASEDIRECTOR_H_INCLUDED
