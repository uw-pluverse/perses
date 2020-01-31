



enum TestEnum {
    BAR {
        private final TestEnum self = BAR;
        private final TestEnum other = QUX;
    },
    QUX
}
