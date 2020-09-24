package monegros.restaurant.entities;

public class Client extends User {
    private String code;

    public Client() {
        super();
    }

    public Client(Long id) {
        super(id);
    }

    public String getCode() {
        return code;
    }

    public void setCode(String code) {
        this.code = code;
    }
}
