# minishell

> Projet en groupe réalisé dans le cadre du cursus de l’école 42.  

## 📌 Objectif

> Reproduire un shell Unix minimaliste en se basant sur le comportement de bash

## ✅ Prérequis

- Système Unix/Linux
- gcc
- Bibliothèques standard

## 📦 Compilation & 🚀 Exécution

```bash
make [bonus]

./minishell
```

## ⚙️ Fonctionnalités principales

- Afficher un prompt
- Historique fonctionnel
- Exécution de commandes (simples ou chaînées)
- Implémentation de certains **builtins** (`cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit`)
- **Pipes**
- **Redirections** :
  - Entrée (`<`)
  - Sortie (`>`, `>>`)
  - **Heredoc** (`<<`)
- Gestion des **variables d'environnement**
- Gestion des **signaux** :
  - `SIGINT` (`Ctrl+C`)
  - `SIGQUIT` (`Ctrl+\`)
- Gestion de `Ctrl+D`
- Bonus : Implémentation des opérateurs ||, && et des parenthèses
