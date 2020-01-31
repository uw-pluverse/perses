


import java.util.*;

class TargetType68 {

    
    static class XYChart<X,Y> {
        static final class Series<X,Y> {
            Series(java.lang.String name, ObservableList<XYChart.Data<X,Y>> data) { }
        }

        static final class Data<X,Y> { }

        ObservableList<XYChart.Series<X,Y>> getData() { return null; }
    }

    
    interface ObservableList<X> extends List<X> {
        boolean setAll(Collection<? extends X> col);
    }

    
    static class FXCollections {
        static <E> ObservableList<E> observableList(List<E> l) { return null; }
    }

    private void testMethod() {
            XYChart<Number, Number> numberChart = null;
            List<XYChart.Data<Number, Number>> data_1 = new ArrayList<>();
            List<XYChart.Data<Number, Number>> data_2 = new ArrayList<>();
            numberChart.getData().setAll(
                    Arrays.asList(new XYChart.Series<>("Data", FXCollections.observableList(data_1)),
                    new XYChart.Series<>("Data", FXCollections.observableList(data_2))));
    }
}
