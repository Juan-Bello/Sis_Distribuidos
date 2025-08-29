import java.rmi.*;

public class SomeClient{
import java.rmi.*;

// Cliente que busca y utiliza el objeto remoto
public class SomeClient{
    public static void main(String args[]){
        try {
            int portNum=1099;

            // URL del registro RMI
            String registryURL ="rmi://serverhost:" + portNum + "/some";
            // Buscar el objeto remoto
            SomeInterface h = (SomeInterface)Naming.lookup(registryURL);
            
            // Invocar método remoto
            String message = h.someMethod1();
            System.out.println(message);
        }
        catch (Exception e) {
            System.out.println("Exception in SomeClient: " + e);
        }
    }
}
