#pragma once
#include <string>
#include <vector>
#include <iostream>

class SymTable 
{
public:
  enum class Kind { Variable, Function, Class };


  struct Symbol 
  {
    std::string name;   
    Kind kind;          
    std::string type;   
    std::string value; 

    std::vector<std::string> params;
  };


private:
  std::string tableName;
  SymTable* parentScope;
  std::vector<Symbol> localSymbols;
  


public:
  SymTable(const std::string name, SymTable* parent = nullptr)
  {
    tableName= name;
    parentScope= parent;
  }



  std::string getName()
  { 
    return tableName; 
  }
  SymTable* getParent()
  { 
    return parentScope; 
  }


  void addSymbol(Symbol s) 
  {
    localSymbols.push_back(s);
  }

  void addClass(std::string name) 
  {
    Symbol s;
    s.name = name; 
    s.kind = Kind::Class;
    addSymbol(s);
  }

  void addFunction(std::string name, std::string returnType, std::vector<std::string> params = {}) 
  {
    Symbol s; 
    s.name = name; 
    s.kind = Kind::Function; 
    s.type = returnType; 
    s.params = params;
    addSymbol(s);
  }

  void addVariable(std::string name, std::string type, std::string value = "") 
  {
    Symbol s; 
    s.name = name; 
    s.kind = Kind::Variable; 
    s.type = type; 
    s.value = value;
    addSymbol(s);
  }




  Symbol* lookupLocal(std::string name)
  {
    for (int i = 0; i < localSymbols.size(); i++)
    {
      if (localSymbols[i].name == name)
      {
        return &localSymbols[i];
      }
    }
    return nullptr;
  }

  
  Symbol* lookup(std::string name)
  {
    SymTable* aux = this;

    while (aux != nullptr)
    {
      for (int i = 0; i < aux->localSymbols.size(); i++)
      {
        if (aux->localSymbols[i].name == name)
        {
          return &aux->localSymbols[i];
        }
      }

      aux = aux->parentScope;
    }

    return nullptr;
  }

  bool existsLocal(std::string name)
  {
    if (lookupLocal(name) != nullptr)
      return true;
    return false;
  }


  void print(std::ostream& out)
  {
    out << "===== Symbol Table: " << tableName << " =====\n";

    if (parentScope == nullptr)
    {
      out << "Parent: none\n";
    }
    else
    {
      out << "Parent: " << parentScope->tableName << "\n";
    }

    if (localSymbols.size() == 0)
    {
      out << "(no symbols)\n\n";
      return;
    }

    for (int i = 0; i < localSymbols.size(); i++)
    {
      out << "- " << localSymbols[i].name << " : ";

      if (localSymbols[i].kind == Kind::Class)
        out << "class";
      else if (localSymbols[i].kind == Kind::Function)
        out << "function";
      else
        out << "variable";

      if (localSymbols[i].type != "")
        out << ", type=" << localSymbols[i].type;

      if (localSymbols[i].value != "")
        out << ", value=" << localSymbols[i].value;

      if (localSymbols[i].params.size() != 0)
      {
        out << ", params=(";

        for (int j = 0; j < localSymbols[i].params.size(); j++)
        {
          out << localSymbols[i].params[j];
          if (j < localSymbols[i].params.size() - 1)
            out << ", ";
        }

        out << ")";
      }

      out << "\n";
    }

    out << "\n";
  }


};

