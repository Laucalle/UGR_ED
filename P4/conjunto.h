/* 
 * conjunto.h
*/

#ifndef __CONJUNTO_H
#define __CONJUNTO_H
#include <string>
#include <vector>
#include <iostream> 
#include "crimen.h"

//! Clase conjunto
/*! Métodos--> conjunto:: conjunto(), insert(), find(),  findIUCR(), findDESCR(), erase(), size(), empty()

 * Tipos--> conjunto::entrada, conjunto::size_type

 * Descripción

* Un conjunto es un contenedor que permite almacenar en orden creciente un conjunto de elementos no repetidos.  En nuestro caso el conjunto va a tener un subconjunto restringido de métodos (inserción de elementos, consulta de un elemento, etc). Este conjunto "simulará" un conjunto de la stl, con algunas claras diferencias pues, entre otros,  no estará dotado de la capacidad de iterar (recorrer) a través de sus elementos.

* Asociado al conjunto, tendremos el tipo  \code conjunto::entrada \endcode que permite hacer referencia al elemento  almacenados en cada una de las posiciones del conjunto, en nuestro caso delitos (crimenes). Para esta entrada el requisito es que tenga definidos el operador< y operator=

* Además encontraremos el tipo \code conjunto::size_type \endcode que permite hacer referencia al número de elementos en el conjunto.

* El número de elementos en el conjunto puede variar dinámicamente; la gestión de la memoria es automática. 
 
 Ejemplo de su uso:
\code
...
conjunto DatosChicago, agresion;
crimen cr;

conjunto.insert(cr);
...
agresion = conjunto.findDESCR("BATTERY");

if (!agresion.empty()){
 cout <<"Tenemos "<< agresion.size() << " agresiones" << endl;
 cout << agresion << endl;
} else "No hay agresiones en el conjunto" << endl;
...
\endcode
 */

template <class Cmp>
class conjunto;


template <class Cmp>
class conjunto
{  
public:
        /** @brief entrada Permite hacer referencia a los elementos almacenados en cada una de las posiciones del conjunto.
         */
	typedef crimen entrada;
	/** @brief size_type Número de elementos en el conjunto.
         */
	typedef unsigned int size_type;
	/** @brief Constructor primitivo. 
	
	*/
	conjunto();

	class iterator;  
	class const_iterator;

	conjunto(iterator ini, iterator fin);
	
	/** @brief Constructor de copia.
	@param[in] d conjunto a copiar
	*/
	conjunto(const conjunto & d);

	/** @brief Devuelve un elemento en una posición concreta.
	@param index posición del elemento
	@return elemento en la posición indicada o elemento por defecto 
	*/
	conjunto::entrada getElement(int & index) const;
		

/** @brief Busca un crimen en el conjunto.
	@param c crimen a buscar
	@return Si existe una entrada en el conjunto devuelve un iterador a su posición. En caso contrario, devuelve end().
*/
	iterator find(const crimen & c);

/** @brief Busca un crimen en el conjunto.
	@param c crimen a buscar
	@return Si existe una entrada en el conjunto devuelve un iterador a su posición. En caso contrario, devuelve end().
*/
	const_iterator find(const crimen & c) const;

/** @brief Busca un crimen en el conjunto.
	@param id identificador del crimen a buscar
	@return Si existe una entrada en el conjunto devuelve un iterador a su posición. En caso contrario, devuelve end().
*/
	iterator find(const long int & id);

/** @brief Busca un crimen en el conjunto.
	@param id identificador del crimen a buscar
	@return Si existe una entrada en el conjunto devuelve un iterador a su posición. En caso contrario, devuelve end().
*/
	const_iterator find(const long int & id) const;

	/** @brief Busca los crímenes con el mismo código IUCR
	@param icur identificador del crimen  buscar
	@return Devuelve un  conjunto con todos los crimenes con el codigo IUCR. Si no existe ninguno devuelve el conjunto vacio.
	@post no modifica el conjunto.
	\verbatim Uso
        vector<crimen> C, A;
        ....
        A = C.findIUCR("0460");
	\endverbatim
	*/
	conjunto findIUCR( const string & iucr) const;

/** @brief Busca los crímenes que contienen una determinada descripción 
	@param descr string que representa la descripcion del delito buscar
	@return Devuelve un  conjunto con todos los crimenes  que contengan descr en su descripcionR. Si no existe ninguno devuelve el conjunto vacio.
	@post no modifica el conjunto.
	\verbatim Uso
        vector<crimen> C, A;
        ....
        A = C.findDESCR("BATTERY");
	\endverbatim
	*/
	conjunto findDESCR( const string & descr) const;

/** @brief Inserta una entrada en el conjunto.
@param e entrada a insertar
@return true si la entrada se ha podido insertar con éxito. False en caso contrario
@post 	 Si e no esta en el conjunto, el size() sera incrementado en 1.
*/
	bool insert( const conjunto::entrada & e);

	
	
/** @brief Borra el delito dado un identificador.

Busca la entrada con id en el conjunto  y si la encuentra la borra.

@param[in] id a borrar
@return true si la entrada se ha podido borrar con éxito. False en caso contrario
@post Si esta en el conjunto su tamaño se decrementa en 1.
*/

	bool erase(const long int & id);


/** @brief Borra un crimen con identificador dado por e.getID() en el conjunto.


Busca la entrada con id en el conjunto (o e.getID() en el segundo caso) y si la encuentra la borra

@param[in] entrada con e.getID() que queremos borrar, el resto de los valores no son tenidos en cuenta
@return true si la entrada se ha podido borrar con éxito. False en caso contrario
@post Si esta en el conjunto su tamaño se decrementa en 1.
*/

	bool erase(const conjunto::entrada & e);

/** @brief Encuentra el primer elemento que cumpla la condición de ser menor o igual que x.
	@param[in] x crimen a comparar
	@return iterador al elemento que cumple la condición o end() si no ha sido encontrado.
*/  
	iterator lower_bound(const entrada & x);

/** @brief Encuentra el primer elemento que cumpla la condición de ser menor o igual que x.
	@param[in] x crimen a comparar
	@return iterador constante al elemento que cumple la condición o end() si no ha sido encontrado.
*/  
	const_iterator lower_bound(const entrada & x) const;

/** @brief Encuentra el primer elemento que cumpla la condición de ser mayor estricto que x.
	@param[in] x crimen a comparar
	@return iterador al elemento que cumple la condición o end() si no ha sido encontrado.
*/
	iterator upper_bound(const entrada & x);

/** @brief Encuentra el primer elemento que cumpla la condición de ser mayor estricto que x.
	@param[in] x crimen a comparar
	@return iterador constante al elemento que cumple la condición o end() si no ha sido encontrado.
*/
	const_iterator upper_bound(const entrada & x) const;


/** @brief Operador de asignación.
@param[in] org conjunto  a copiar
Crea un conjunto duplicado exacto de org.
*/
	conjunto & operator=( const conjunto & org);

	/** @brief Número de entradas en el conjunto.
@post  No se modifica el conjunto.
*/

	size_type size() const;


/** @brief Chequea si el conjunto está vacío.
   @return true si size()==0, false en caso contrario
*/
	bool empty() const;

	
	// ================================= ITERADORES ========================================/ 


////////////////////////////----ITERATOR----///////////////////////////

/**@brief devuelve iterador al inicio del conjunto
*/	 
	iterator begin();

/**@brief devuelve iterador al final (posición siguiente al último del conjunto
*/
	iterator end();

/** @brief class iterator
 * forward iterador sobre el conjunto, LECTURA
 *  iterator() ,operator*(), operator++, operator++(int) operator=, operator==, operator!=
 * */

    class iterator{

    public:

/** @brief Constructor primitivo. 
	
*/		
		iterator();

/** @brief Constructor de copia.
	@param[in] it iterador a copiar
*/
		iterator(const iterator & it);

/** @brief Constructor a partir de un iterador de vector de entradas.
	@param[in] it iterador a asignar
*/
		iterator(const std::vector<entrada>::iterator & it);

/** @brief Operador de acceso al elemento apuntado por el iterador.
*/
		conjunto::entrada & operator*();

/** @brief Operador de asignación.
@param[in] org iterador a copiar
*/
		iterator & operator=(const iterator & it);

/** @brief Operador de incremento postfijo.
@param vacío para distinguirlo del incremento prefijo
*/
		iterator operator++( int );

/** @brief Operador de incremento prefijo.
*/
		iterator & operator++();

/** @brief Operador de decremento postfijo.
@param vacío para distinguirlo del decremento prefijo
*/
		iterator operator--(int);

/** @brief Operador de decremento prefijo.
*/
		iterator & operator--();

/** @brief Operador de igualdad.
@param it iterador a comparar.
@return true o false según cumpla la comparación lógica.
*/
		bool operator==(const iterator & it);

/** @brief Operador de desigualdad.
@param it iterador a comparar.
@return true o false según cumpla la comparación lógica.
*/
		bool operator!=(const iterator & it);

	private:

		friend class conjunto;
		std::vector<entrada>::iterator itv;

	};

////////////////////////////----CONST_ITERATOR----///////////////////////////

/** @brief  
     @return Devuelve el const_iterator a la primera posición del conjunto.
@post no modifica el conjunto
*/ 
	const_iterator cbegin() const;

/** @brief iterador al final
     @return Devuelve el iterador constante a la  posición final del conjunto.
@post no modifica el conjunto
*/
	const_iterator cend() const;

/** @brief class const_iterator
 * forward iterador constante sobre el conjunto, Lectura 
 *  const_iterator ,operator*, operator++, operator++(int) operator=, operator==, operator!=
 * */
	class const_iterator{

	public:

/** @brief Constructor primitivo. 
	
*/
		const_iterator();

/** @brief Constructor de copia.
	@param[in] it iterador a copiar
*/
		const_iterator(const const_iterator & it);

/** @brief Constructor a partir de un const_iterador de vector de entradas.
	@param[in] it iterador a asignar
*/
		const_iterator(const std::vector<entrada>::const_iterator & it);

/** @brief Convierte iterator en const_iterator
*/
		const_iterator(const iterator & it);

/** @brief Operador de acceso al elemento apuntado por el iterador.
*/
		const conjunto::entrada & operator*() const;

/** @brief Operador de asignación.
@param[in] org iterador a copiar
*/
		const_iterator & operator=(const const_iterator & it);

/** @brief Operador de incremento postfijo.
@param vacío para distinguirlo del incremento prefijo
*/
		const_iterator operator++( int );

/** @brief Operador de incremento prefijo.
*/
		const_iterator & operator++();

/** @brief Operador de decremento postfijo.
@param vacío para distinguirlo del decremento prefijo
*/
		const_iterator operator--(int);

/** @brief Operador de decremento prefijo.
*/
		const_iterator & operator--();

/** @brief Operador de igualdad.
@param it iterador a comparar.
@return true o false según cumpla la comparación lógica.
*/
		bool operator==(const const_iterator & it);

/** @brief Operador de desigualdad.
@param it iterador a comparar.
@return true o false según cumpla la comparación lógica.
*/
		bool operator!=(const const_iterator & it);

	private:
	 
		std::vector<entrada>::const_iterator c_itv;
		friend class conjunto;

	}; 
	 
private:

	Cmp comp;
	std::vector<crimen> vc; // vector ORDENADO por crimen.id que almacena los elementos del conjunto
 
/** \invariant
 
 IR: rep ==> bool
 
\li Para todo i, 0 <= i < vc.size() se cumple
	vc[i].ID > 0;
\li Para todo i, 0 <= i <= D.dic.size()-1 se cumple
	vc[i].ID< vc[i+1].ID

*/

	
/** @brief Chequea el Invariante de la representacion 
@return true si el invariante es correcto, falso en caso contrario
*/
	bool cheq_rep( ) const;

//  declaracion del operator<< como metodo amigo
//	friend ostream & operator << ( ostream & sal, const conjunto<Cmp> & D);

 // Clases amigas
	friend class iterator;
	friend class const_iterator;
	friend class description_iterator;
	friend class const_description_iterator;
	friend class arrest_iterator;
	friend class const_arrest_iterator;

};


/** @brief imprime todas las entradas del conjunto 
@post  No se modifica el conjunto.
*/
template <class Cmp>
ostream & operator << ( ostream & sal, const conjunto<Cmp> & D);

#include "conjunto.hxx"

#endif