    /*#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!
    !                                                                            #
    #                                                                            !
    !   Programmer:     Nick Martinez                                            #
    #   Class:          COSCI 436 - SAT 8:15 - 10:30AM                           !
    !   Instructor:     Milan Samplewala                                         #
    #   Date:           11/30/2018                                               !
    !                                                                            #
    #          LAB 9 - Implementing List, Stacks Queues and Priority Queues      ! 
    !                                                                            #
    #!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!#!



________/\\\\\\\\\_______/\\\\\__________/\\\\\\\\\\\__________/\\\\\\\\\__/\\\\\\\\\\\_        
_____/\\\////////______/\\\///\\\______/\\\/////////\\\_____/\\\////////__\/////\\\///__       
___/\\\/_____________/\\\/__\///\\\___\//\\\______\///____/\\\/_______________\/\\\_____      
__/\\\______________/\\\______\//\\\___\////\\\__________/\\\_________________\/\\\_____     
_\/\\\_____________\/\\\_______\/\\\______\////\\\______\/\\\_________________\/\\\_____    
_\//\\\____________\//\\\______/\\\__________\////\\\___\//\\\________________\/\\\_____   
__\///\\\___________\///\\\__/\\\_____/\\\______\//\\\___\///\\\______________\/\\\_____  
____\////\\\\\\\\\____\///\\\\\/_____\///\\\\\\\\\\\/______\////\\\\\\\\\__/\\\\\\\\\\\_ 
_______\/////////_______\/////_________\///////////___________\/////////__\///////////__


 _______________________/\\\________/\\\\\\\\\\_____________/\\\\\____________________
  ____________________/\\\\\______/\\\///////\\\________/\\\\////____________________
 ___________________/\\\/\\\_____\///______/\\\______/\\\///___________________________
  ________________/\\\/\/\\\____________/\\\//_____/\\\\\\\\\\\_______________________
 _______________/\\\/__\/\\\___________\////\\\___/\\\\///////\\\______________________
  ____________/\\\\\\\\\\\\\\\\___________\//\\\_\/\\\______\//\\\____________________
 ____________\///////////\\\//___/\\\______/\\\__\//\\\______/\\\___________________
   ____________________\/\\\____\///\\\\\\\\\/____\///\\\\\\\\\/______________________
  _____________________\///_______\/////////________\/////////______________________


    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!
    THIS IS UNORIGINAL SOURCE FOR MYARRAYLIST - EXERCISE 24.1 IMPLEMENTATION IN MyList.java !!!



*/


public class MyArrayList<AnyType> implements Iterable<AnyType>
{
    /**
    * Construct an empty ArrayList.
    */
    public MyArrayList( )
    {
        clear( );
    }

    /**
    * Returns the number of items in this collection.
    * @return the number of items in this collection.
    */
    public int size( )
    {
        return theSize;
    }

    /**
    * Returns true if this collection is empty.
    * @return true if this collection is empty.
    */ 
    public boolean isEmpty( )
    {
        return size( ) == 0;
    }

    /**
    * Returns the item at position idx.
    * @param idx the index to search in.
    * @throws ArrayIndexOutOfBoundsException if index is out of range.
    */
    public AnyType get( int idx )
    {
        if( idx < 0 || idx >= size( ) )
            throw new ArrayIndexOutOfBoundsException( "Index " + idx + "; size " + size( ) );
        return theItems[ idx ];    
    }

    /**
    * Changes the item at position idx.
    * @param idx the index to change.
    * @param newVal the new value.
    * @return the old value.
    * @throws ArrayIndexOutOfBoundsException if index is out of range.
    */
    public AnyType set( int idx, AnyType newVal )
    {
        if( idx < 0 || idx >= size( ) )
            throw new ArrayIndexOutOfBoundsException( "Index " + idx + "; size " + size( ) );
        AnyType old = theItems[ idx ];    
        theItems[ idx ] = newVal;

        return old;    
    }

    @SuppressWarnings("unchecked")
    public void ensureCapacity( int newCapacity )
    {
        if( newCapacity < theSize )
            return;

        AnyType [ ] old = theItems;
        theItems = (AnyType []) new Object[ newCapacity ];
        for( int i = 0; i < size( ); i++ )
            theItems[ i ] = old[ i ];
    }

    /**
    * Adds an item to this collection, at the end.
    * @param x any object.
    * @return true.
    */
    public boolean add( AnyType x )
    {
        add( size( ), x );
        return true;            
    }

    /**
    * Adds an item to this collection, at the specified index.
    * @param x any object.
    * @return true.
    */
    public void add( int idx, AnyType x )
    {
        if( theItems.length == size( ) )
            ensureCapacity( size( ) * 2 + 1 );

    for( int i = theSize; i > idx; i-- )
        theItems[ i ] = theItems[ i - 1 ];

        theItems[ idx ] = x;
        theSize++;  
    }

    /**
    * Removes an item from this collection.
    * @param idx the index of the object.
    * @return the item was removed from the collection.
    */
    public AnyType remove( int idx )
    {
        AnyType removedItem = theItems[ idx ];

        for( int i = idx; i < size( ) - 1; i++ )
            theItems[ i ] = theItems[ i + 1 ];
        theSize--;    

        return removedItem;
    }

    /**
    * Change the size of this collection to zero.
    */
    public void clear( )
    {
        theSize = 0;
        ensureCapacity( DEFAULT_CAPACITY );
    }

    /**
    * Obtains an Iterator object used to traverse the collection.
    * @return an iterator positioned prior to the first element.
    */
    public java.util.Iterator<AnyType> iterator( )
    {
        return new ArrayListIterator( );
    }

    /**
    * Returns a String representation of this collection.
    */
    /**
    * This is the implementation of the ArrayListIterator.
    * It maintains a notion of a current position and of
    * course the implicit reference to the MyArrayList.
    */
    private class ArrayListIterator implements java.util.Iterator<AnyType>
    {
        private int current = 0;
        private boolean okToRemove = false;

        public boolean hasNext( )
        {
            return current < size( );
        }


        public AnyType next( )
        {
            if( !hasNext( ) ) 
                throw new java.util.NoSuchElementException( ); 

                okToRemove = true;    
                return theItems[ current++ ];
            }

            public void remove( )
            {
                if( !okToRemove )
                    throw new IllegalStateException( );

                MyArrayList.this.remove( --current );
                okToRemove = false;
            }
    }

    private static final int DEFAULT_CAPACITY = 10;

    private AnyType [ ] theItems;
    private int theSize;
}

