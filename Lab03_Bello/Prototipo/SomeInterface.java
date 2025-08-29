import java.rmi.*;

public interface SomeInterface extends Remote {
    // Cabecera del primer método remoto
    public String someMethod1( )
        throws java.rmi.RemoteException;
    // Cabecera del segundo método remoto
    public int someMethod2( float parameter) throws
        java.rmi.RemoteException;
}
