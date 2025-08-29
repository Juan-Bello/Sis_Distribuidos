import java.rmi.*;
import java.rmi.server.*;

// Implementación de la interfaz remota que extiende UnicastRemoteObject
public class SomeImpl extends UnicastRemoteObject implements SomeInterface {
    // Constructor que lanza RemoteException
    public SomeImpl() throws RemoteException { super( ); }
    
    // Implementación del primer método remoto
    public String someMethod1( ) throws RemoteException
    { return "metodo1"; }
    
    // Implementación del segundo método remoto
    public int someMethod2(float a) throws RemoteException
    { return 55; }
}