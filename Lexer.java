import java.util.*;
import java.util.regex.*;

public class Lexer {
    private static final List<PadraoToken> padroesToken = new ArrayList<>();
    private static final Pattern tokenRegex;

    static {
        padroesToken.add(new PadraoToken(Token.Tipo.PCHAVE, "\\b(if|else|while|return)\\b"));
        padroesToken.add(new PadraoToken(Token.Tipo.IDENTIFICADOR, "\\b[A-Za-z_][A-Za-z0-9_]*\\b"));
        padroesToken.add(new PadraoToken(Token.Tipo.NUMERO, "\\b\\d+(\\.\\d+)?\\b"));
        padroesToken.add(new PadraoToken(Token.Tipo.OPERADOR, "[+\\-*/=<>!]+"));
        padroesToken.add(new PadraoToken(Token.Tipo.STRING, "\"([^\"\\\\]|\\\\.)*\""));
        padroesToken.add(new PadraoToken(Token.Tipo.SIMBOLO, "[(){};]"));
        padroesToken.add(new PadraoToken(Token.Tipo.WHITESPACE, "[ \t\r\n]+"));

        StringBuilder tokenRegexBuilder = new StringBuilder();
        for (PadraoToken pd : padroesToken) {
            tokenRegexBuilder.append(String.format("|(?<%s>%s)", pd.getTipo().name(), pd.getPadrao()));
        }
        tokenRegex = Pattern.compile(tokenRegexBuilder.substring(1));
    }

    public List<Token> transformarEmToken(String codigo) {
        List<Token> tokens = new ArrayList<>();
        Matcher matcher = tokenRegex.matcher(codigo);
        int linha = 1;
        int coluna = 1;
        while (matcher.find()) {
            for (PadraoToken pd : padroesToken) {
                if (matcher.group(pd.getTipo().name()) != null) {
                    String valor = matcher.group(pd.getTipo().name());
                    if (pd.getTipo() != Token.Tipo.WHITESPACE) {
                        tokens.add(new Token(pd.getTipo(), valor, linha, coluna));
                    }
                    coluna += valor.length();
                    break;
                }
            }
            if (matcher.group().contains("\n")) {
                linha++;
                coluna = 1;
            }
        }
        return tokens;
    }

    private static class PadraoToken {
        private final Token.Tipo tipo;
        private final String padrao;

        public PadraoToken(Token.Tipo tipo, String padrao) {
            this.tipo = tipo;
            this.padrao = padrao;
        }

        public Token.Tipo getTipo() {
            return tipo;
        }

        public String getPadrao() {
            return padrao;
        }
    }

}
