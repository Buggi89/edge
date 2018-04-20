#ifndef FIELD_H
#define FIELD_H

class field {
  
  public:
    enum Symmetry {
      NOSYM=0,
      SYM  =1,
      ASYM =2
    };

    enum Type {
      SCALAR  =0,
      VECTOR  =1,
      COVECTOR=2,
      TENSORDD=3
    };

    string          name; 
    field::Symmetry *symmetry[3];
    field::Type     type;

    field(string, int, int, field::Type);
    ~field();
    virtual double getValue() = 0;
    virtual double getValue(int) = 0;
    virtual double getValue(int,int) = 0;
    virtual void   setValue(double) = 0; 
    virtual void   setValue(double,int) = 0; 
    virtual void   setValue(double,int,int) = 0;

  protected:    
    int            n_total;
    int            n[2];
    double         *value;

};

class scalar_field : public field {

  public:
    scalar_field(string name) : field(name,1,1,SCALAR) {}
    double getValue();
    double getValue(int) { return getValue(); }
    double getValue(int,int) { return getValue(); }
    void   setValue(double); 
    void   setValue(double value,int) { setValue(value); }
    void   setValue(double value,int,int) { setValue(value); }

};

#endif // FIELD_H
