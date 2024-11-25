function my_mesh(X, Y, Z, title_str)
    mesh(X, Y, Z);
    title(title_str);
    grid on;
    box off;
    setup_image_folder();
    exportgraphics(gcf, title_str + '.png', 'Resolution', 300); cd('..');
end

