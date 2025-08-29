import java.rmi.*;
import java.rmi.server.*;
import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;

// Servidor que publica el objeto remoto en el registro RMI
public class SomeServer {
    public static void main(String args[]) {
        try{
            // Crear instancia del objeto remoto
            SomeImpl exportedObj = new SomeImpl();

            int portNum=1099;
            // Iniciar el registro RMI
            startRegistry(portNum);

            // Publicar el objeto en el registro
            String registryURL = "rmi://localhost:"+portNum+"/some";
            Naming.rebind(registryURL, exportedObj);
            System.out.println("Some Server ready.");
        }
            catch (Exception ex) {
            System.out.println("Exception: "+ex);
        }
    }

    // Método para iniciar el registro RMI en el puerto especificado
    private static void startRegistry(int RMIPortNum) throws RemoteException {
        try {
            // Intentar obtener el registro existente
            Registry registry= LocateRegistry.getRegistry(RMIPortNum);
            registry.list( ); // Verificar si está activo
        }
        catch (RemoteException ex){
            // Si no existe, crear uno nuevo
            System.out.println("RMI registry cannot be located at port" + RMIPortNum);
            Registry registry= LocateRegistry.createRegistry(RMIPortNum);
            System.out.println("RMI registry created at port " + RMIPortNum);
        }
    }
}