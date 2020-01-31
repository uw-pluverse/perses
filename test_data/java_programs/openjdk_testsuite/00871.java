



enum TestEnum {
    BAR,
    QUX,
    BAZ {
        private final TestEnum a = BAR;
        private final TestEnum b = QUX;
    }
}
