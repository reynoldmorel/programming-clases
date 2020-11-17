package monegros.restaurant.entities;

//import java.util.ArrayList;
import java.util.List;

public class FinalProduct extends Product {
    private List<Product> products;

    public FinalProduct() {
        super();
        //this.products = new ArrayList<>();
    }

    public FinalProduct(Long id) {
        super(id);
    }

    public List<Product> getProducts() {
        return products;
    }

    public void setProducts(List<Product> products) {
        this.products = products;
    }
}
