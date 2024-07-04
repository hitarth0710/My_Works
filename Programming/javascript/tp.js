const x = {
    get value() {
        return 0;
    },
    set value(v) {
        console.log("Setter called");
    },
};

x.value &&= 2;
