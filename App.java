import java.util.List;
import java.util.Scanner;

public class App {
    public static void main(String[] args) {
        Lexer lexer = new Lexer();
        String codigo = "if (x < 10) {\n    return x + 1;\n} else {\n    return 0;\n}";

        List<Token> tokens = lexer.transformarEmToken(codigo);
        for (Token token : tokens) {
            System.out.println(token);
        }
    }
}
