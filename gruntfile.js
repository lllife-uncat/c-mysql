
module.exports = function(grunt) {
  grunt.initConfig({

    watch: {
      c: {
        files: ["src/**/*.c"],
        tasks: ["shell:compile"]
      }
    },
    shell: {
      compile: {
        command: "make"
      }
    }
  });

  grunt.loadNpmTasks("grunt-contrib-watch");
  grunt.loadNpmTasks("grunt-shell");
  grunt.registerTask("default", ["shell:compile", "watch:c"]);
};
