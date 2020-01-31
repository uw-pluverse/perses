





import java.awt.*;
import java.awt.event.*;

public class DeadCode6 extends Window
{
    public DeadCode6( Frame parent ) {
        super( parent );
    }

    public void init() {
        final DeadCode6 wndThis = this;

        
        addWindowListener( new WindowAdapter () {
            public void windowClosing( WindowEvent evt ) {
                wndThis.doCancelAction();
            }
        } );
    }

    public void doCancelAction() { }
}
